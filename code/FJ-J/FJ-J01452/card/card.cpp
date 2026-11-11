#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5000005],f[3000005],cnt[3000005];
void func(int x){
	stack<int>s;
	for(int i=x;i<=n;i++){
		if(f[a[i]]){
			while(s.top()!=a[i]){
				f[s.top()]=0;
				s.pop();
			}
			s.pop();
			s.push(a[i]);
			f[a[i]]=1;
		}else{
			s.push(a[i]);
			f[a[i]]=1;
		}
	}
	while(!s.empty()){
		cnt[s.top()]++;
		s.pop();
	}
	return ;
}
signed main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fill(f+1,f+1+n,0);
		func(i);
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}

