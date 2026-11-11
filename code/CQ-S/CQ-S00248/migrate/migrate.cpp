#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int c,t;
int n,d;
int a[N];
int minn[N],num[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int sum=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			memset(minn,-1,sizeof(minn));
			memset(num,0,sizeof(num));
			minn[1]=1;
			num[1]=1;
			for(int i=1;i<n;i++){
				for(int j=i+1;a[i]+d>=a[j]&&j<=n;j++){
					if(minn[i]+1<minn[j]||minn[j]==-1){
						minn[j]=minn[i]+1;
						num[j]=num[i];
					}
					else if(minn[i]+1==minn[j]){
						num[j]++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(num[i]==2){
					sum+=n-i+1;
				}
			}
			cout<<sum<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int k=1;k<n;k++){
			memset(minn,-1,sizeof(minn));
			memset(num,0,sizeof(num));
			minn[k]=1;
			num[k]=1;
			for(int i=k;i<n;i++){
				for(int j=i+1;a[i]+d>=a[j]&&j<=n;j++){
					if(minn[i]+1<minn[j]||minn[j]==-1){
						minn[j]=minn[i]+1;
						num[j]=num[i];
					}
					else if(minn[i]+1==minn[j]){
						num[j]++;
					}
				}
			}
			for(int i=1;i<=n;i++){
//				cout<<num[i]<<" ";
				if(num[i]==2){
					sum++;
				}
			}
//			cout<<"\n";
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
/*
11 2
5 3
1 2 3 4 5
6 2
1 2 3 4 5 6

*/
