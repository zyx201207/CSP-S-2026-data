#include<bits/stdc++.h>
using namespace std;
int a[500001],bj[300001],maxn,b[300001];
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bj[a[i]]=i;
		maxn=max(maxn,a[i]);
	}
	bool f=0;
	for(int i=1;i<=maxn;i++){
		if(!bj[a[i]]){f=1;break;}
	}
	if(!f){
		for(int i=1;i<=m;i++){
			cout<<bj[i]<<" ";
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!bj[a[j]]) st.push(a[j]),bj[a[j]]=j;
				else{
				while(st.size()>bj[a[j]]){
					bj[st.top()]=0;
					st.pop();
				}
			}
			
			}
			for(int y=i;y<=n;y++){
				if(bj[a[y]]) b[a[y]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[a[i]]<<" ";
	}
	return 0;
}
