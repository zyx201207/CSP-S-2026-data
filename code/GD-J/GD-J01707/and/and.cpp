#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[114514*2],k[30]={1};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//for(int i=1;i<=30;i++){
	//	k[i]=k[i-1]*2;
	//}
	sort(a+1,a+1+n,greater<int>());
	//结论假了(⊙﹏⊙) 
	//ans=a[1];
	//cout<<a[1]<<a[2]<<endl;
	//for(int i=2;i<=m;i++){
	//	ans&=a[i];
	//}
	//int dis=lower_bound(k+1,k+30,ans)-k-1;
	//9:07过了 
	for(int i=1;i<=33;i++){
		int tp=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			tp&=a[j];
		}
		ans=max(ans,tp);
	}
	cout<<ans;
}
