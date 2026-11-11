#include <bits/stdc++.h> 
#define ll long long 
using namespace std;

const int N = 1e5 + 10; 

ll n,m;
ll a[N];
//ll vis[N];

//struct node {
//	int l,r;
//};
//node gg[N];
ll de[N];

int main (){
	
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	
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
		de[i] = a[i];
	}
	
	for (int i = 2;i <= n;i++){
//		vis[a[i]]--;
		de[i] = max(de[i],de[i - 1] & de[i]);
	}
	cout<<de[n];
	
	return 0;
}
