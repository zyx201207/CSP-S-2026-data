#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[500005],ans[300005];int n,m;
void chafen(int x){
	if(x>=n)return;
	int y=b[a[x]];
	c[x]-=1;
	c[y]+=1;
	//cout<<x<<' '<<y<<endl;
	chafen(y+1);
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		c[i]=1;
	}
//	for(int i=1;i<=m;i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	for(int i=n;i>=1;i--){
		chafen(i);
//		for(int i=1;i<=n;i++){
//			cout<<c[i]<<' ';
//		}
//		cout<<endl;
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=c[i];
		ans[a[i]]+=cnt;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
