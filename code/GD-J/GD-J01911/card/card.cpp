#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m;
ll num[200010];
ll sit[200010];
string s;
void games(ll cnt,string a){
	for(int i=0;i<=m;i++)sit[i]=-1;
	a.erase(0,cnt-1);
	ll len=a.size();
	for(int i=0;i<len;i++){
		if(sit[a[i]-'0']==-1)sit[a[i]-'0']=i;
		else{
			for(int j=sit[a[i]-'0'];j<i;j++){
				sit[a[j]-'0']=-1;
				a[j]='0';
			}
			sit[a[i]-'0']=i;
		}
	}
	for(int i=0;i<len;i++){
		if(a[i]!='0')num[a[i]-'0']++;
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;cin>>a;
		s=s+a;
	}
	for(int i=1;i<=n;i++)games(i,s);
	for(int i=1;i<=m;i++)cout<<num[i]<<" ";
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
