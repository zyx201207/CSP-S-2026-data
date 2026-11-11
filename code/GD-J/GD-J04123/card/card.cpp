#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5;
ll n,m;
ll a[N];
ll p[N];
ll x[N],rear=1;
ll cnt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		rear = 0;
		memset(p,0,sizeof(p));
		for(int j=i+1;j<=n;j++){
			if(p[a[j]]!=0){
				for(int j=p[a[j]]+1;j<=rear;j++){
					p[x[j]]=0;
				}
				rear = p[a[j]];
			}else{
				rear++;
				x[rear] = a[j];
				p[a[j]] = rear;
			}
		}
		for(int i=1;i<=rear;i++){
			cnt[x[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	cout<<endl;
	return 0;
}
