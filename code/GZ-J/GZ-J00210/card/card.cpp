//GZ-J00210 ∫Î“„÷–—ß —Ó∫∆”Ó 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[211000],b[211000];
bool visited[211000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	ll x=a[n];
	for(int i=1;i<=m;i++) {
		b[i]=m;	
	}
	b[x]=n;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

