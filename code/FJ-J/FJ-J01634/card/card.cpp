#include <bits/stdc++.h>
using namespace std;
int n,m,mx,a[200010],p[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	for(int j=0;j<n;j++){
		map<int,int> mp;
		stack<int> st;
		for(int i=j;i<n;i++){
			if(mp.find(a[i])==mp.end()){
				mp[a[i]]=1;
				st.push(a[i]);
			}else{
				while(st.top()!=a[i]) st.pop();
			}
		}
		while(!st.empty()){
			p[st.top()]+=1;
			st.pop();
		}
	}
	for(int w=1;w<=mx;w++){
		cout<<p[w]<<" ";
	}
	return 0;
}
