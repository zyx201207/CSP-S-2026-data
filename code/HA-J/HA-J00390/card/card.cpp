#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],n,m,ans[N];
bool qw(int qq,int z){
	if(qq==1)return 0;
	for(int i=1;i<qq;i++)if(b[i]==z)return 1;
	return 0;
}
void chu(int z){
	for(int i=n;i>=1;i--){
		if(b[i]!=z)b[i]=-1;
		else break;
	}
}
void cha(int j){
	for(int i=1;i<=n;i++){
		if(b[i]!=-1){
			ans[b[i]]++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int j=1;j<=n;j++){
		memset(b,-1,sizeof(b));
		for(int i=j;i<=n;i++){
			b[i]=a[i];
			if(qw(i,a[i]))b[i]=-1,chu(a[i]);
		}
		cha(j);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
