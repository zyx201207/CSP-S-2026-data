#include<bits/stdc++.h>
using namespace std;
int n, m;
string MAX;
struct qwer{
	int a;
	string s;
}a[20010];
void ssj(int c, int f, string now){
	if(c>m)  return ;
	for(int i=f+1;i<=n;i++){
		string b1, b2;
		for(int j=0;j<min(now.size(), a[j].s.size());j++){
			if(now[j]=='1'&&a[i].s[j]=='1')  b1+='1';
			else b1+='0';
		}
		ssj(c++, i, b1);
		if(now.size()<b1.size())  now=b1;
		else if(now.size()>b1.size())  continue;
		else {
			for(int i=now.size()-1;i>=0;i++){
				if(now[i]=='1'&&b1[i]=='0')	 break;
				if(now[i]=='0'&&b1[i]=='1'){
					now=b1;
					break;
				}
			}
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		int q=a[i].a;
		string s;
		while(q>0){
			s+=q%2+'0';
			q/=2;
		}
		for(int j=s.size()-1;j>=0;j--){
			a[i].s+=s[j];
		}
	}
	for(int i=1;i<=n;i++){
		string a1=a[i].s;
		ssj(1, i, a1);
		if(MAX.size()<a1.size())  MAX=a1;
		else if(MAX.size()>a1.size())  continue;
		else {
			for(int i=0;i<MAX.size();i++){
				if(MAX[i]=='1'&&a1[i]=='0')	 break;
				if(MAX[i]=='0'&&a1[i]=='1'){
					MAX=a1;
					break;
				}
			}
		}
	}
	int mumber=0, bei=2;
	mumber+=MAX[MAX.size()-1]-'0';
	for(int i=MAX.size()-2;i>0;i--){
		mumber+=bei*(MAX[i]-'0');
		bei*=2;
	}
	cout<<mumber;
	return 0;
}
