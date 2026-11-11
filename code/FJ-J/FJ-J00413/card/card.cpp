#include<bits/stdc++.h> 
using namespace std;
int a[500050];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    for(int i=1;i<=m;i++){
    	cout<<n<<" ";
    }
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
