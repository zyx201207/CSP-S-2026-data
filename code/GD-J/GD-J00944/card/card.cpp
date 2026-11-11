#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],z[N],x[N];
string da[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(z,0,sizeof(z));
		int kl=0;
		for(int j=i;j<=n;j++){
			kl++;
			if(z[a[j]]){
				kl=z[j];
			}
			z[a[j]]=kl;
			da[i]+=a[j];
		}
	}
	for(int i=1;i<m;i++) cout << m << " ";
	cout << m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
} 




