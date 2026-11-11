#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int path[500005];
long long ans[300005];
long long in[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]<a[i]+1){
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	
	
	
	
	return 0;
}
