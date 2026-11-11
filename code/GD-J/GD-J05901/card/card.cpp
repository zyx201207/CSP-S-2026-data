#include <bits/stdc++.h> 
using namespace std;
int a[500010];
int b[500010];
int c[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	c[i]++;
	}
	for(int i=1;i<=m;i++){
		if(c[i]){
			cout<<n<<" ";
		}
	} 
}
