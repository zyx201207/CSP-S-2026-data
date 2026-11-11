#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool flag[200005];
void search(int deep,int sum){
	if(deep==m){
		if(sum>ans) ans=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			search(deep+1,sum&a[i]);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		flag[i]=1;
		search(1,a[i]);
		flag[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}
// DFSÆ­·Ö 
