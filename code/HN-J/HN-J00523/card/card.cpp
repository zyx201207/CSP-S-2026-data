#include <bits/stdc++.h> 
#define ll long long 
using namespace std;

const int N = 1e5 + 10; 

ll n,m;
ll a[N];
ll vis[N];

//struct node {
//	int l,r;
//};
//node gg[N];
//ll de[N];

int main (){
	
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","r",stdout);
	
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
//		vis[a[i]]++;
//		if (vis[a[i]] % 2 == 0){
//			gg[i].r = i;
//		}
//		if (vis[a[i]] == 1){
//			ans[i].l = i;
//			de[++tot] = a[i];
//		}
//		de[i] = a[i];
	}
	
	for (int i = 1;i < n;i++){
//		vis[a[i]]--;
		char s[N];
		ll se[N],sd[N];
		ll x[N];
		for (int j = 1;j <= n;j++){
			s[i] = a[i];
			se[a[i]]++;
			if (sd[a[i]] == 1){
				sd[a[i]] = i;
			}
			if (se[i] >= 2){
				x[sd[a[i]]] = 1;
				x[i + 1] -= 1;
			}	
		}
//		de[i] = max(de[i],de[i - 1] & de[i]);

		for (int j = 1;j <= m;j++){
			cout<<vis[i]<<" ";
		}
	}
	
	return 0;
}
