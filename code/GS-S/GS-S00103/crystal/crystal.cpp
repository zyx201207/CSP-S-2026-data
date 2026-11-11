#include<bits/stdc++.h>
#define long long ll 
using namespace std;
int a[maxn];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=1;i<=m;i++){
    	ans++;
	}
	cout<<ans;
    return 0;
} 
