#include<bits/stdc++.h>
using namespace std;
const int kMaxN=2e5+5;
int n,m;
int a[kMaxN];
string s[kMaxN];
stack<int>tmp;
int ans;
string F(int x){
	string ans="";
	while(!tmp.empty())tmp.pop();
	while(x){
		tmp.push(x%2);
		x/=2;
	}
	for(int i=1;i<=32-tmp.size();i++){
		ans+="0";
	}
	while(!tmp.empty()){
		ans+=char(tmp.top()+'0');
		tmp.pop();
	}
	return ans;
}
int vis[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=F(a[i]);
	}
	for(int i=0;i<=31;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			bool flag=true;
			for(int k=0;k<=31;k++){
				if(vis[k]==1&&s[j][k]=='0'){
					flag=false;
					break;
				}
			}
			if(flag&&s[j][i]=='1')cnt++;
		}
		if(cnt>=m){
			vis[i]=1;
			ans+=pow(2,(31-i));
		}
	}
	cout<<ans;
	return 0;
}
