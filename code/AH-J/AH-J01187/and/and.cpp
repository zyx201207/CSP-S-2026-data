#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
ll arr[200005];
bool isbinnum[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<=31;j++){
			if(arr[i]==long(pow(2,j)-1)){
				isbinnum[i]=true;
			}
		}
	}
	ll ans=-1,mx=-1,zh=0;
	for(int j=0;j<m;j++){
		ans=-1;
		mx=-1;
		zh=0;
		for(int i=0;i<n;i++){
			if(arr[i]>mx){
				mx=max(mx,arr[i]);
				zh=i;
			}
		}
		
		if(ans==-1){
			ans=mx;
		}else{
			ans=(ans&mx);
		}
		arr[zh]=-1;
	}
	cout<<ans;
	return 0;
}



