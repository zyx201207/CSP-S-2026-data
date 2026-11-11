#include <bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[1000010];
int dp(int a,int b){
	int c=1;
	for(int i=a;i<=n;i++){
		if(b==m &&c>ma){
			return c;
		}
		c=c&i;
		dp(i,b+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	cout<<dp(m,n);
	return 0;
}
