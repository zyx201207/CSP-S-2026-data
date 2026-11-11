#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 9e4 + 10;
const int NN = 1e6;
int cc[N][N];
int cnt[NN]; 

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int res = 0;
	while(t--){
		res = 0;
		int n,d;
		cin>>n>>d;
		int x[n];
		int mx = INT_MIN;
		for(int i =0;i<NN;i++){
			cnt[i] = 0;
		}
		for(int i = 0;i<n;i++){
			cin>>x[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = i + 1;j<n;j++){
				int tp = x[j] - x[i];
				cc[i][j] = (tp + 1) / d;
				mx = max(mx,cc[i][j]);
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = i + 1;j<n;j++){
				cnt[cc[i][j]]++;
			}
			for(int i = 1;i<=mx;i++){
				if(cnt[i] == 2){
					res++;
				}
			}
		}
		for(int i = 0;i<=mx;i++){
			if(cnt[i] == 2){
				res++;
			}
			for(int i =0;i<NN;i++){
				cnt[i] = 0;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

