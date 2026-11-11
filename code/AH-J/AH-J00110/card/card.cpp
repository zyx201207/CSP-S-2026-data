#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],m,ans[300010],pd=0;
stack<long long> st;
map<long long,long long> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])pd=1;
	}
	if(!pd){
		for(int i=1;i<=n;i++)for(int j=a[i];j<=m;j++)ans[j]++;
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			mp.clear();
			for(int j=i;j<=n;j++){
				if(!mp[a[j]])st.push(a[j]),mp[a[j]]++;
				else if(mp[a[j]]){
					while(!st.empty()){
						long long tmp=st.top();
						if(tmp==a[j])break;
						else st.pop(),mp[tmp]--;
					}
				}
			}
			while(!st.empty()){
				long long tp=st.top();
				ans[tp]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}
