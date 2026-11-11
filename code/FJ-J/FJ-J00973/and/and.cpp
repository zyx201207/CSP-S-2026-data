#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200005],p[200005];
void ff(long long x,long long y){
	if(y==m){
		maxx=max(maxx,x);
		return ;
	}
	int u=0,s;
	for(int i=1;i<=n;i++){
		if(!p[i]&&u){
			x=x&a[i];
			p[i]=1;
			u=0;
			s=i;
		}else{
			if(!p[i]){
				if(x<x&a[i]){
					p[s]=0;
					x&=a[i];
					s=i;
				}
			}
	    }
	}ff(x,y+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else{
		if(m==2){
			maxx=a[1]&a[2];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}cout<<maxx;
		}if(m==n){
			maxx=a[1];
			for(int i=2;i<=n;i++){
				maxx&=a[i];
			}cout<<maxx;
		}else{
			ff(a[n],1);
			cout<<maxx;
		}
	}
	return 0;
}
