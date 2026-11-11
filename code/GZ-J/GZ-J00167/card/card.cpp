//GZ-J00167 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],fir[N],ch[N],st[N],dp[N],cnt[N],liu[N],cha[N],tim[N],ans[M];
//cha(fen)

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ch[n+1]=2147483647;
	st[n+1]=2147483647;
	for(int i=n;i>=1;i--){
		ch[i]=ch[i+1];
		st[i]=st[i+1];
		if(fir[a[i]]!=0){
			ch[i]=fir[a[i]];
			st[i]=i;
		//	cout<<".";
		}
		fir[a[i]]=i;

	}
	for(int j=1;j<=n;j++){
	//	cout<<ch[j]<<" ";
	}
//	cout<<"\n";

	for(int i=n;i>=1;i--){
		if(ch[i]==2147483647){
			dp[i]=i;
			liu[i]=n-i+1;
		}
		else{
			dp[i]=dp[ch[i]];
			liu[i]=st[i]-i;
		}
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(ch[i]!=2147483647){
			cnt[ch[i]]+=cnt[i];
	//		cout<<"cnt["<<ch[i]<<"]="<<cnt[ch[i]]<<"\n";	
		}
		
	}//cout<<"."; 
	for(int i=1;i<=n;i++){
		cha[i]+=cnt[i];
		cha[i+liu[i]]-=cnt[i];
	}
	for(int i=1;i<=n;i++){
		tim[i]=tim[i-1]+cha[i];
		ans[a[i]]+=tim[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
