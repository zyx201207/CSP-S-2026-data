#include<bits/stdc++.h>
using namespace std;
int n,m;
long long r,a[20005];
long long cf(int x){
	long long ans=1;
	for(int i=1;i<=x;i++) ans*=2;
	return ans;
}
long long awy(long long x,long long y){
	int a[31]={0},b[31]={0},as=0,bs=0,ans=0;
	for(int i=1;x;i++){
		a[i]=x%2;
		x/=2;
		if(x/2==0) as=i;
	}
	for(int i=1;y;i++){
		b[i]=+y%2;
		y/=2;
		if(y/2==0) bs=i;
 	}
    for(int i=max(as,bs);i>=1;i--){
    	if(a[i]==b[i] && a[i]==1) ans+=cf(i-1);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1) for(int i=1;i<=n;i++) ans=max(a[i],ans);
	else if(m==2){
		for(int i=1;i<n;i++){
    		for(int j=i+1;j<=n;j++) ans=max(ans,awy(a[i],a[j]));
		}
	}
	else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=awy(ans,a[i]);
	} 
	else if(n==3){
		for(int i=1;i<n-1;i++){
			for(int b=i+1;b<n;b++){
				for(int c=b+1;c<=n;c++) ans=max(ans,awy(awy(a[i],a[b]),a[c]));
			}
		}
	}
    cout<<ans;
	return 0;
}/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
