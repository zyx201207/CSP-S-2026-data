#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<string> chuan;
	for(int i=0;i<n;i++){
		long long a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			chuan.push_back(b);
		}
	}
	
	long long a=0,b=0,c=0;
	for(string i:chuan){
		a++;
		b++;
	}
	string l[a];
	for(string i:chuan){
		l[a-1]=i;
		a--;
		c++;
	}
	
	long long tt=0;
	for(int i=0;i<b/2;i++){
		if(l[i]!=l[c-1]){
			tt++;
		}
		c--;
	}
	cout<<tt;
	return 0;
}
