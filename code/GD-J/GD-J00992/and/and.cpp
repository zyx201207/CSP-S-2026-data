#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[200100][35];
int lie[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(v,0,sizeof(v));
	memset(lie,0,sizeof(lie));
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		int j=0;
		for(;x;x>>=1){
			if(x&1){
				lie[j]++;
				v[i][j]=1;
			}
			j++;
		}
	}
	vector<int>a;
	a.reserve(n);
	int p=0;
	ll ans=0;
	for(int i=30;i>=0;i--){
		if(lie[i]>=m){
			for(int j=1;j<=n;j++){
				if(v[j][i])a.push_back(j);
			}
			p=i-1;
			ans=1<<i;
			break;
		}
	}
	if(a.size()==0){cout<<0<<'\n';return 0;}
	if(a.size()<m){cout<<ans<<'\n';return 0;}
	int alen=a.size();
	for(int i=p;i>=0;i--){
		if(alen<m)break;
		if(lie[i]>=m){
			int sum=0;
			for(int &j:a){
				if(j==-1)continue;
				if(v[j][i]){
					sum++;
					if(sum>=m){
						ans+=1<<i;
						break; 
					}
				}
				else j=-1,alen--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
