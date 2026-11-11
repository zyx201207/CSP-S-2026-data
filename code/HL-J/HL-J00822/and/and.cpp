#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+200;
ll n,m,a[N],k[N][35],num[35],key,sum,ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],pos=1;
		while(x>0){
			k[i][pos]=x&1;
			x/=2;
			pos++;
		}
		for(int j=1;j<=31;j++){
			if(k[i][j])num[j]++;
		}
	}
	sum=n;
	for(int i=31;i>0;i--){
		if(num[i]>=m){
			key=0;
			for(int j=1;j<=sum;j++){
				if(k[j][i]){
					key++;
					for(int z=1;z<=31;z++){
						k[int(key)][z]=k[j][z];
					}
				}
			}
			sum=key;
			int x=1;
			for(int j=1;j<i;j++){
				x=x*2;
			}
			ans+=x;
			memset(num,0,sizeof(num));
			for(int j=1;j<=sum;j++){
				for(int z=1;z<=31;z++){
					if(k[j][z])num[z]++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
