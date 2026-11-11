/*
HAPPY AFO :)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+5;
int n,m,a[N],k[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(k,0x3f,sizeof(k));
	sort(a+1,a+1+n);
	int maxn=0,sum=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			sum++;
		}else{
			maxn=max(maxn,sum);
			sum=1;
		}
	}
	maxn=max(maxn,sum);
	if(maxn==n){
		cout<<n<<"\n";
		return 0;
	}
	if(n<=5000){
		k[1]=0;
		for(int i=2;i<=n;i++){
			k[i]=(a[i]-a[i-1])*(i-1);
			k[i]+=k[i-1];
		}
		int maxxn=0;
		for(int i=n;i>=1;i--){
			if(k[i]<=m){
				maxxn=max(maxxn,i);
				break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				k[j]-=(a[i]-a[i-1]);
			}
			for(int j=n;j>=1;j--){
				if(k[j]<=m){
					maxxn=max(maxxn,j-i);
					break;
				}
			}
		}
		cout<<maxxn<<"\n";
	}else{
		k[1]=0;
		for(int i=2;i<=n;i++){
			k[i]=(a[i]-a[i-1])*(i-1);
			k[i]+=k[i-1];
		}
		for(int i=n;i>=1;i--){
			if(k[i]<=m){
				cout<<max(maxn,i)<<"\n";
				break;
			}
		}
	}

	return 0;
}
/*
5 3
5 8 9 10 10
0 3 5 8  8
0 0 1 3  3
0 0 0 1  1
*/
