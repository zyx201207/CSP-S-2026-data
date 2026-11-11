#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> pii;
const int N=2e5+10;
vector<int> G[N];
int n,m,t;
pii a[N];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].first>=a[r].first){
			if(a[l].second!=a[r].second){
				ans+=a[r].first;
			}
			a[l].first-=a[r].first;
			r-=1;
		}
		else{
			if(a[l].second!=a[r].second){
				ans+=a[l].first;
			}
			a[r].first-=a[l].first;
			l+=1;
		}
	}
	cout<<ans;
}
