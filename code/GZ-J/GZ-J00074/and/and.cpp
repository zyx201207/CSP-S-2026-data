//×¼¿¼Ö¤ºÅ£ºGZ-J00074 ÐÕÃû£ººú¾þºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int mx=INT_MIN;
int n,m,a[N],b[N],sumn;

void dfs(int k,int sumn){
	if(k==m+1){
		mx=max(mx,sumn);
	}else{
		for(int i=1;i<=n;i++){
			dfs(k+1,sumn&a[i]);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		dfs(1,a[i]);
	}
	cout<<mx;
	return 0;
}
