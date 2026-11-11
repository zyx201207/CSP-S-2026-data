#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;

int n,m,a[N],t[N],ans,vis[N];
void f(int cnt){
	if(cnt==m+1){
		int num=a[t[1]];
		for(int i=2;i<=m;i++){
			num&=a[t[i]];
			vis[t[i]]=0;
		}
		ans=max(ans,num);
		
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			t[cnt]=i;
			f(cnt+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	f(1);
	cout<<ans;
}
//5 3 31 3 1 15 7
//15
