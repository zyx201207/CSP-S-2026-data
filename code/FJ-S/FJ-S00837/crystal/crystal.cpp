#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],s=1,s1,sz;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		c[i]=c[i+1]+a[i+1]-a[i];
	}
	for(int i=2;i<=n;i++){
		s1=0;
		sz=1;
		for(int j=i-1;j>=1;j--){
			if(c[j]-c[i]+s1<=m){
				s1+=c[j]-c[i];
				sz++;
			}
			else{
				break;
			}
		}
		s=max(s,sz);
	}
	cout<<s;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
