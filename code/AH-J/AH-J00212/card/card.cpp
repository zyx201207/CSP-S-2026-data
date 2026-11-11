#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<ll> s;
ll cnt[300010],sum[300010],num[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,a[500010];
	cin>>n>>m;
	bool c=1,d=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) c=0;
		num[a[i]]++;
		
	}
	if(c||d){
		for(int i=2;i<=m;i++){
			num[i]+=num[i-1];
		}
		for(int i=1;i<=m;i++){
			cout<<num[i]<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(cnt[a[i]]==1){
				while(s.top()!=a[i]){
					cnt[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[i]);
				cnt[a[i]]=1;
			}
		}
		while(!s.empty()){
			sum[s.top()]++;
			cnt[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
