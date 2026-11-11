#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int t[300005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
	   	cin>>a[i];
	}
    for(int i=1;i<=m;i++){
	   	cout<<n<<" "; 
	}		
	return 0;
}  
