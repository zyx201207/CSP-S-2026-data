#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
long long cnt[N];
void play(int x){
	map<int,bool> mp;
	stack<int> st;
	for(int i=x;i<=n;i++){
		if(mp[a[i]]==0){
			st.push(a[i]);
			mp[a[i]]=1;
		}
		else{
		while(st.top()!=a[i]){
			st.pop();
		}
		}
	}
	while(!st.empty()){
		cnt[st.top()]++;
		st.pop(); 
	}
	return ;
}
signed main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}

for(int i=1;i<=n;i++){
	play(i);
}
for(int i=1;i<=m;i++){
	cout<<cnt[i]<<" ";
}
cout<<endl;
return 0;
}

