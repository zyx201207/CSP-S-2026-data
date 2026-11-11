#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct st{
	int w;
	int t[25];
}a[500005];
int c,n,m,d,q,x,y,k,di,s,z,z_1,z_2,z_3;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i].w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>di>>s;
			a[di].t[i]=s;
			if(i==2&&a[di].t[1]!=0&&n==2){
				z=di;
			}
			if(n==3){
				if(i==2&&a[di].t[1]!=0) z_1=di; //1 2
				if(i==3&&a[di].t[1]!=0) z_2=di; //1 3
				if(i==3&&a[di].t[2]!=0) z_3=di; //2 3
			}
//			cout<<a[di].t[i]<<" ";
		}
//		cout<<"\n";
	}
//	cout<<z_1<<z_2<<z_3<<"\n";
	int tj;
    if(n==3){
    	
		if(z_1==z_2&&z_1==z_3) tj=1;
		if(z_1==z_2&&z_1!=z_3) tj=2; //1
		if(z_1!=z_2&&z_1==z_3) tj=3; //2
		if(z_2==z_3&&z_1!=z_3) tj=4; //3
		if(z_1!=z_2&&z_2!=z_3&&z_1!=z_3) tj=5;	
	}
	
	while(q--){
		cin>>x>>y;
		int ans=0;
		if(n==2){
			if(a[x].t[1]!=0&&a[y].t[1]!=0) ans=a[x].w+a[x].t[1]+a[y].w+a[y].t[1];
			else if(a[x].t[2]!=0&&a[y].t[2]!=0)  ans=a[x].w+a[x].t[2]+a[y].w+a[y].t[2];
			else ans=a[x].w+a[x].t[1]+a[x].t[2]+a[y].w+a[y].t[1]+a[y].t[2]+a[z].t[1]+a[z].t[2];
//			if(ans==16) cout<<a[x].t[1]<<" "<<a[x].t[2]<<" "<<a[y].t[1]<<" "<<a[y].t[2]<<" "<<a[z].t[1]<<" "<<a[z].t[2]<<"\n";
			cout<<ans<<"\n";
		}
		if(n==1){
			ans=a[x].w+a[x].t[1]+a[y].w+a[y].t[1];
			cout<<ans<<"\n";
		}
		if(n==3){
			if(tj==1){
				if(a[x].t[1]!=0&&a[y].t[1]!=0) ans=a[x].w+a[x].t[1]+a[y].w+a[y].t[1];
				else if(a[x].t[2]!=0&&a[y].t[2]!=0)  ans=a[x].w+a[x].t[2]+a[y].w+a[y].t[2];
				else if(a[x].t[3]!=0&&a[y].t[3]!=0)  ans=a[x].w+a[x].t[3]+a[y].w+a[y].t[3];
				else ans=a[x].w+a[x].t[1]+a[x].t[2]+a[y].w+a[y].t[1]+a[y].t[2]+a[z_1].t[1]+a[z_1].t[2]+a[x].t[3]+a[y].t[3];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
