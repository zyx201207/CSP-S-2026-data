#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long dp[500005];
long long a[500005];
long long vis[500005];
stack<int> s;
int main(){
	long long ji=0;
	long long ou=0; 
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
   for(int i=1;i<=n;i++){
   	cin>>a[i]; 
   }
   for(int i=1;i<=m;i++){
   	cout<<a[i]%n*m<<" ";
   }
	return 0;
}
