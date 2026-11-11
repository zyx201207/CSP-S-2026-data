#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+1e1;
struct node{
	int num;
	string s;
} nodes[N];
string f(int x){
	string k="",ans="";
	while(x!=0){
		int b=x%2;
		k+=b+'0';
		x/=2;
	}
	for(int i=k.size()-1;i>=0;i--){
		ans+=k[i];
	}
	return ans;
}
bool cmp(node n1,node n2){
	return n1.num>n2.num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>nodes[i].num;
		nodes[i].s=f(nodes[i].num);
	}
	sort(nodes+1,nodes+1+n,cmp);
	string ans=nodes[1].s;
	for(int i=2;i<=m;i++){
		int mn=min(nodes[i].s.size(),ans.size());
		string cn="";
		for(int j=0;j<mn;j++){
			if(nodes[i].s[j]==ans[j]){
				cn+=ans[j];
			} else {
				cn+='0';
			}
		}
		ans=cn;
	}
	int wq=1,cnt=0;
	for(int i=ans.size()-1;i>=0;i--){
		cnt+=(ans[i]-'0')*wq;
		wq*=2;
	}
	cout<<cnt;
    return 0;
}
