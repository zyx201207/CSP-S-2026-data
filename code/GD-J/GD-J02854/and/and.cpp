#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[200005][35],v[200005],c=1,mx=33,s[50],sum[50],ans,pw[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],f=0;
		while(x){
			p[i][++f]=x%2;
			x/=2;
		}
	}
	while(c){
		c=0;
		for(int i=1;i<=35;i++){
			s[i]=0;
		}
		for(int j=1;j<=mx;j++){
			for(int i=1;i<=n;i++){
				if(!v[i]) 
				s[j]+=p[i][j];
			}	
			if(s[j]>=m)
			c=j;
		}
		mx=c-1;
		sum[c]=1;
		for(int i=1;i<=n;i++){
			if(!p[i][c])
			v[i]=1;
		} 
	}
	pw[0]=1;
	for(int i=1;i<=33;i++){
		pw[i]=pw[i-1]*2;
		ans+=pw[i-1]*sum[i];
	}
	cout<<ans;
	return 0;
}
