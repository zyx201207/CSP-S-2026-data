#include<bits/stdc++.h>
using namespace std;

#define N 500005
#define M 300005

int a[N];
long long mul[M]; 
int lst[M];
int ans[M];
int nxt[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mul[a[i]]++;
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i==lst[a[i]]) mul[a[i+1]]+=mul[a[i]]; 
	}
	
	for(int i=1;i<=m;i++){
		cout<<mul[i]<<' ';
	}
	cout<<'\n';
//	for(int i=n;i>=1;i--){
//		if(i==lst[a[i]]){
//			
//		}
//	}
	
	return 0;
}

