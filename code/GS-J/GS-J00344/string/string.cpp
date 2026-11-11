#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	int sz;
	bool fl=false;
	vector<string>zm;
	vector<string>cc;
	vector<string>zz;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sz>>s;
		for(int j=0;j<sz;j++){
			zm.push_back(s);
		}
	}
	for(int i=0;i<zm.size()/2;i++){
		cc.push_back(zm[i]);
	}
	reverse(cc.begin(),cc.end());
	reverse(zm.begin(),zm.end());
	for(int i=0;i<cc.size();i++){
		zz.push_back(zm[i]);
	}
	zz.pop_back();
	for(int i=0;i<zz.size();i++){
		zm.push_back(zz[i]);
	}
	for(int i=0;i<zm.size();i++){
		if(zm[i]==cc[i]){
			fl=true;
		}
	}
	if(fl){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<zm.size();i++){
			if(zm[i]==cc[i]){
				cout<<0;
				return 0;
			}
			else{
				if(i!=0){
					if(zm[i]==zm[i-1]&&cc[i]!=cc[i-1]&&cc[i]!=zm[i]&&cc[i-1]!=zm[i-1]){
						int a=cc.size();
						cout<<a;
						return 0;
					}
					else if(zm[i]==zm[i-1]&&cc[i]!=cc[i-1]&&cc[i]==zm[i]){
						int b=cc.size();
						cout<<b;
						return 0;
					}
					else if(zm[i]==zm[i-1]&&cc[i]!=cc[i-1]&&cc[i-1]==zm[i-1]){
						int c=cc.size();
						cout<<c;
						return 0;
					}
					else if(zm[i]!=zm[i-1]&&cc[i]==cc[i-1]&&cc[i]!=zm[i]&&cc[i-1]!=zm[i-1]){
						int d=cc.size();
						cout<<d;
						return 0;
					}
					else if(zm[i]!=zm[i-1]&&cc[i]==cc[i-1]&&cc[i]==zm[i]){
						int e=cc.size();
						cout<<e;
						return 0;
					}
					else if(zm[i]!=zm[i-1]&&cc[i]==cc[i-1]&&cc[i-1]==zm[i-1]){
						int f=cc.size();
						cout<<f;
						return 0;
					}
				}
			}
		}
	}
}
