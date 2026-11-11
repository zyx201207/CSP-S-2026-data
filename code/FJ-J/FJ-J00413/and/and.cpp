#include<bits/stdc++.h> 
using namespace std;
int a[500050];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
