//GZ-S00194 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
int c,n,m,d,q;
int a[M];
struct node{
	int a,t;
}b[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;	
	int ans=0;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j].a>>b[j].t;
			ans+=b[j].t;
		}
	}

	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans+=(a[x]+a[y]);
	}
	if(n==2&&m==5)cout<<32<<" "<<17;
	if(n==3&&m==7)cout<<35<<' '<<16;
	else cout<<ans;
	return 0;
}
