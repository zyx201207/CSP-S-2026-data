#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("ctystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
			cin>>a[i];
		}
    sort(a+1,a+n+1);
    int mid=ceil((double)n/2);
    int mv=a[mid];
    ll ans=0;
    for(int i=mid-1;i>=1;i--){
			int cost=mv-a[i];
			if(a[i]<mv&&m>=cost){
				a[i]+=cost;
				m-=cost;
			}
    }
    for(int i=1;i<=n;i++){
			if(a[i]==mv)ans++;
    }
    cout<<ans<<'\n';
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
