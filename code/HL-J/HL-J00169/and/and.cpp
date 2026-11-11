#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
const int N=1e5+5;
int a[N];
int b[N];
ll ans=-8968926589;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n,m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i){
				continue;
			}else{
				ll c=a[i]&a[j];
				ans=max(ans,c);
			}
		}
	
		
	}cout<<ans;
	
	
	
	
	
	return 0;
}
