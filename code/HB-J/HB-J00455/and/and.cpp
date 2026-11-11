#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	int t=0,d=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		while(a[i]<=0){
			a[i]/=2;
			if(a[i]%2==0){
				s[i]='0';
			}
			if(a[i]%2==1 && s[i]=='1'){
				s[i]='1';
			}
		}
	}
	for(int i=s.size();i>=1;i--){
		t+=s[i]*d;
		d*=2;
	}
	cout<<t;
	return 0;
}
