#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1000005],b[50],c[50],e[50],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int d=a[i],d1=a[i-1];
		b[50]=c[50]=e[50]={};
		int p=0;
		while(d!=0){
			b[++p]=d%2;
			d=d/2;
		}
		p=0;
		while(d1!=0){
			c[++p]=d1%2;
			d1=d1/2;
		}
		for(int i=1;i<=50;i++){
			if(b[i]==1&&c[i]==1) e[i]=1;
			else e[i]=0;
		}
		int q=0,l=1;
		for(int i=1;i<=50;i++){
			q=q+e[i]*l;
			l=l*2;
		}
		ans=max(q,ans);
	}
	cout<<ans;
	return 0;
}
