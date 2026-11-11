#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]) flag=0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[i]!=a[n]) ans[a[n]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]&&i>1) ans[a[i-1]]=i-1;
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		int cnt[300005]={0};
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				while(s.top()!=a[j]) cnt[s.top()]--,s.pop();
			}
			else cnt[a[j]]++,s.push(a[j]);
		}
		while(!s.empty()){
			cnt[s.top()]--;
			if(!cnt[s.top()]) ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
