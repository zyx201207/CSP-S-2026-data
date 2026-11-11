#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],num[2000005],dis[5005][5005],c,ans,d,e,i,j,k,t,x,y,fl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			fl=0;
			for(i=1;i<=n;i++)cin>>a[i];
			x=a[2]-a[1];
			for(i=1;i<n;i++){
				if(x*i<d&&x*(i+1)>=d){
					cout<<n-i<<endl;
					fl=1;
				}
			}
			if(!fl)cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			j=i;
			for(e=i+1;e<=n;e++){
				while(a[e]-a[j]>d)j++;
				dis[i][e]=dis[i][j]+1;
			}
		} 
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				num[j]=0;
			}
			num[i]=1;
			j=i;
			for(e=i+1;e<=n;e++){
				while(a[e]-a[j]>d)j++;
				for(x=j;x<e;x++){
					if(dis[i][x]+dis[x][e]==dis[i][e])num[e]+=num[x];
				}
				if(num[e]==2)ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
