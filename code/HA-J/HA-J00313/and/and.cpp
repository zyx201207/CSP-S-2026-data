#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxn=INT_MIN;
int an[200005];
string er(ll a){
	string s;
	while(a!=0){
		s+=(a%2+'0');
		a/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string yu(string a,string b){
	string s;
	int la=a.size(),lb=b.size();
	int maxn=max(la,lb);
	for(int i=0;i<abs(maxn-la);i++){
		a="0"+a;
	}
	for(int i=0;i<abs(maxn-lb);i++){
		b="0"+b;
	}
	for(int i=0;i<maxn;i++){
		if(a[i]=='0' ||b[i]=='0') s+="0";
		else s+="1";
	}
	return s;
}
ll fan(string a){
	ll ans=0;
	for(int i=a.size()-1;i>=0;i--){
		ans+=(a[i]-'0')*pow(2,a.size()-i-1);
	}
	return ans;
}
void DFS(int x,ll sum,int cnt){
	if(cnt==m){
		maxn=max(maxn,sum);
		return ;
	}
	if(x==n+1) return;
	DFS(x+1,sum,cnt);
	if(cnt==0) DFS(x+1,an[x],cnt+1);
	else DFS(x+1,fan(yu(er(sum),er(an[x]))),cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	DFS(1,1,0);
	cout<<maxn;
	return 0;
}
