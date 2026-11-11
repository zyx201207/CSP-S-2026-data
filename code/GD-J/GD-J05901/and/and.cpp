#include <bits/stdc++.h> 
using namespace std;
int a[200010];
int b[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i]; 
	} 
	sort(a+1,a+n+1,greater<int>());
	cout<<a[m];
}
