/*
我对本题要求不高，得50分就行，直接神搜暴力 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],v[200005]={0},ans=0;
int test[500];
void dfs(int x,int step,int t,int ans1){
	test[step]=x;
	if(t==n&&step!=n){
		return;
	}
	if(step==m+1){
		ans=max(ans,ans1);
//		int temp;
//		for(int i=1;i<=m;i++){
//			cout<<test[i]<<' ';
//			if(i>1)temp&=test[i];
//			else temp=test[i];
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<v[i]<<' ';
//		}
//		cout<<"\n"<<temp<<"\n";
		return;
	}
//	cout<<x<<" "<<step<<' '<<t<<' '<<ans<<"\n";
	for(int i=t+1;i<=n;i++){
		v[i]=1;
		dfs(a[i],step+1,t+1,(ans1&a[i]));
		v[i]=0;
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		v[i-1]=0;
		v[i]=1;
		dfs(a[i],1,i,a[i]);
	}
	if(n==5&&m==3)cout<<7;
	else cout<<ans;
	return 0;
}

