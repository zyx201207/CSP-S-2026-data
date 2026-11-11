#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=1e6*2+10;
int c,t;
ll n,d,ans=0;
ll arr[MAXN];

bool check(int l,int r){
	if(l<=n && r<=n) return true;
	else return false;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		
		int l=1,r=l+3;
		while(l<r && check(l,r)){
			if(arr[r]-arr[l]<=d || r-l<3){
				r++;
			}
			else{
				if(arr[r]-arr[l+1]<=d && arr[r-1]-arr[l]<=d && arr[r]-arr[l+1]==arr[r-1]-arr[l]){
					if(r-l>=4){
						if(qwe(l,r,arr[r]-arr[l+1])){
							ans++;
						}
					}
					else ans++;
				}
				l++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
