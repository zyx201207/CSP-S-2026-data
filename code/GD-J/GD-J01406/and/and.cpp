#include<bits/stdc++.h>
using namespace std;
int val[1000005];
bool flag[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=30;i>=0;i--){
		int ji=0;
		for(int j=1;j<=n;j++)if(!flag[j] && ((val[j]>>i)&1))ji++;
		if(ji>=k){
			ans+=(1<<i);
			for(int j=1;j<=n;j++)if(!flag[j] && ((val[j]>>i)&1)==0)flag[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
/*
35min Ç©µôÇ°ÈýÌâ 
*/
