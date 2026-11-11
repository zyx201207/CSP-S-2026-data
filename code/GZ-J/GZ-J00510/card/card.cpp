//GZ-J00510 金浩 兴义市弘毅中学 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[5000005];
int f[3000007];
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
 ios::sync_with_stdio(false);	
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			f[a[i]]++;
	}
for(int i=1;i<=3000004;i++){
			if(f[i]!=0){
				cout<<f[i]<<" ";
			}
	}
	
	
	
	return 0;
} 
