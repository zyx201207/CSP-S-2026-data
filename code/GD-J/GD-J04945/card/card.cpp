#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,cnt[300005],ans[300005];
stack<long long>b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				while(b.top()!=a[j]) cnt[b.top()]--,b.pop();
			}
			else{
				b.push(a[j]);
				cnt[a[j]]++;
			}
		}
		while(b.size()) ans[b.top()]++,b.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
