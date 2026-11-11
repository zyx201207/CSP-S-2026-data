#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t[500005];
int la[500005],a[500005],nex[500005],id[500005];
stack<int> s;
int query(int x){
	int ans=0;
	while(x){
		ans+=t[x];
		x-=x&-x;
	}
	return ans;
}
void update(int x,int k){
	while(x<=n){
		t[x]+=k;
		x+=x&-x;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(la[a[i]]) nex[la[a[i]]]=i;
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!nex[i]) continue; 
		while(!s.empty()&&nex[s.top()]<nex[i]) s.pop();
		if(!s.empty()) id[i]=s.top();
		s.push(i);
	}
	memset(la,0,sizeof(la));
	for(int i=1;i<=n;i++){
		update(i,1);
		if(la[a[i]]){
			update(la[a[i]],1),update(i,-1);
			int tmp;
			if(id[la[a[i]]]) tmp=query(id[la[a[i]]]),update(la[a[i]]+1,tmp),update(i,-tmp);
			tmp=query(la[a[i]]);
			update(la[a[i]],-tmp),update(i,tmp);
			s.push(i);
		}
		la[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(!la[i]) cout<<"0 ";
		else cout<<query(la[i])<<' ';
	}
	return 0;
}

