#include<bits\stdc++.h>
using namespace std;
int n,m,a[200005],b[68],c[68];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){cout<<a[n];return 0;}
	if(m==n){
		int t,t1=0,shu;
		for(int i=a[n];i>0;i/=2){
			b[++t]=i%2;
		}
		for(int i=n-1;i>=1;i--){
			for(int j=a[i];j>0;j/=2){
				c[++t1]=j%2;
			}
		}
		for(int i=1;i<=min(t,t1);i++){
			if(b[i]!=c[i]) b[i]=0;
			else b[i]=1;
		}
		t=min(t,t1);
		for(int i=t;i>=1;i--){
			shu=shu*2+b[i];
		}
		cout<<shu;
	}
	return 0;
}
