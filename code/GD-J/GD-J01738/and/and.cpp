#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
const int LOG=30;
bool erJinZhip[N+1][LOG+1];
int sum[LOG+1];
int mi[LOG+1];
bool alive[N+1];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		alive[i]=true;
		int a;
		cin>>a;
		int cur=LOG;
		while(a>0){
			erJinZhip[i][cur]=a&1;
			sum[cur]+=a&1;
			a>>=1;
			cur--;
		}
//		for(int j=1;j<=LOG;j++){
//			cerr<<erJinZhip[i][j]<<" ";
//		}
//		cerr<<endl;
	}
	mi[0]=1;
	for(int i=1;i<=LOG;i++){
		mi[i]=mi[i-1]*2;
//		cerr<<sum[i]<<" ";
	}
//	cerr<<endl;
	int ans=0;
	for(int i=1;i<=LOG;i++){
		if(sum[i]<m) continue;
		ans+=mi[30-i];
		for(int j=1;j<=n;j++){
			if(!alive[j]) continue;
			if(!erJinZhip[j][i]){
				alive[j]=false;
				for(int k=1;k<=LOG;k++){
					if(erJinZhip[j][k]){
						sum[k]--;
					}
				}
			}
		}
	}
	cout<<ans;
//	cerr<<ans<<endl;
//	for(int i=1;i<=LOG;i++){
//		cerr<<sum[i]<<" ";
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
