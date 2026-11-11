#include<bits/stdc++.h>
using namespace std;
struct zd{
	char c;
	long long cs;
}a[200005];
bool cmp1(zd p,zd q){
	return p.cs>q.cs;
}
bool cmp2(zd p,zd q){
	return p.c<q.c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,s=0;
	cin>>n;
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++) cin>>a[i].cs>>a[i].c;
	for(int i=1;i<=n;i++){
		if(a[i].c==a[i+1].c){
			a[i+1].cs+=a[i].cs;
			a[i].cs=0;
		}
		else continue;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(a[i].cs==0){
			k=i-1;
			break;
		}
	}
	sort(a+1,a+1+k,cmp2);
	if(k==1) cout<<0;
	for(int i=1;i<=k;i++){
		s+=a[i].cs;
	}
	cout<<s-ceil(s/2);
	return 0;
}
