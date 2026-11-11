#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin,(x).end
#define fi first
#define se second
#define pb push_back
ll a[100009];
ll b[100009];
int n,m;
void f(int k){
	b[k]=b[k+1];
	for(int i=k+1;i<=n;i++){
		if(a[i]==a[k]){
			for(int j=k;j<=k;j++){
				if(a[j]==k&&b[k]>0){
					b[k]--;
				}
			}
		}
	}
	f(k-1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(n);
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}























































































































































































