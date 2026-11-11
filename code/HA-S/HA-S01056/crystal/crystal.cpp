#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,maxx=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		a[i]=b;
		s+=b;
	}
	s/=n;
	int mini=100000007,w;
	for(int i=1;i<=n;i++){
		int r=s-a[i];
		if(r<0){
			r=r-(2*r);
		}
		if(r<mini){
			mini=r;
			w=i;
		}
	}
	mini=a[w];
	for(;;){
		int minini=100000007,u,ma=maxx;
		for(int i=1;i<=n;i++){
			if(a[i]-mini<minini && a[i]!=mini){
				minini=a[i];
				u=i;
			}
		}
		a[u]++;
		m--;
		int ax=0;
		for(int i=1;i<=n;i++){
			if(a[i]==mini){
				ax++;
			}
		}
		ma=max(ax,ma);
		maxx=ma;
		if(m==0){
			break;
		}
	}
	cout<<maxx;
	return 0;
}
