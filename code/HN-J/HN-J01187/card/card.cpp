//was OI a dream
#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],cnt[500005];
stack<int>stk;
int main(){
	freopen("card.in",r,stdin);
	freopen("card.out","w",stdout);
	memset(s,0,sizeof(s));
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			stk.push(s[j]);
			
		}
	}
	return 0;
} 
