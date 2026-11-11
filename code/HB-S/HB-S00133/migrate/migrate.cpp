#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[2000010];
void solv1(){
	int npc=a[2]-a[1];
	int mm=m/npc*2-1;
	int ans=n-mm;
	cout<<ans<<endl;
}
int solv2(int bi,int nn,int ji){
	int ans=0;
	for(int i=nn;i>=bi;i--){
		if(a[i]-a[ji-1]<=m){
			if(a[i]-a[ji-2]>m){
				ans++;
			}else{
				break;
			}
		}
	}
	return ans;
}
void solv3(){
	int zhi1=0,zhi2=0,zhi3=0,ans=0;
	while(zhi1<=n){
		if(zhi3==zhi2){
			zhi1=zhi2+1;
			for(int i=zhi1;i<=n;i++){
				if(a[i]<=a[zhi1]+m){
					zhi2=i;
				}else{
					break;
				}
			}
			for(int i=zhi2;i<=n;i++){
				if(a[i]<=a[zhi2]+m){
					zhi3=i;
				}else{
					break;
				}
			}
		}else{
			while(a[zhi2+1]-a[zhi1]<=m&&zhi2+1<=n){
				zhi2++;
			}
			while(a[zhi3+1]-a[zhi2]<=m&&zhi3+1<=n){
				zhi3++;
			}
		}
		ans+=solv2(zhi1,zhi3,zhi2);
		zhi1++;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(a,-100000,sizeof(a));
	//	int npc;
		for(int i=1;i<=n;i++){
			cin>>a[i];
	/*		if(a[1]<0){
				npc=0-a[1];
				a[i]+=npc;
			}*/
		}
		if(c==11||c==12){
			solv1();
		}else if(c==13||c==14){
			int ji=0;
			for(int i=1;i<=n;i++){
				if(a[1]+m>=a[i]){
					ji=i;
				}else{
					break;
				}
			}
			cout<<solv2(1,n,ji);
		}else{//shililaozixiangchuzhengjiele
			solv3();
		}
	}
	return 0;
}
//1 1 24 50 1 2 3 4 5 6 24 35 45 48 53 60 61 63 67 71 76 85 95 97 103 107 109 111
