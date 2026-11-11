#include<bits/stdc++.h>
using namespace std;
const int M=2*1e5+10;
int n,m,a[M],s[M],dp[M],cnt=0,maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			s[i]=max(s[i-1]&a[i],a[i-1]&a[i]);
			maxn=max(maxn,s[i]);
		}
	}
	for(int i=2;i<=n;i++){
		if(cnt+1<m){
			dp[i]=max(dp[i],dp[i-1]&a[i]);cnt++;
		}else{
			dp[i]=max(dp[i-1],a[i]&maxn); 
		}
	}
	cout<<dp[n]<<endl;
	fclose(stdin);fclose(stdout);
	/*for(int i=1;i<=n;i++){
		cout<<s[i]<<' ';                            调试前缀和（与）数组  
	}*/
	return 0;
}
