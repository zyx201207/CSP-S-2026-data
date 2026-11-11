#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,maxa,len=0;
ll a[N],ans=0;
string b[N];
string f(int x){
	string res;
	int cnt=0;
	while(x>=1){
		cnt++;
		if(x%2==1) res+="1";
		else res+="0";
		x/=2;
	}
	reverse(res.begin(),res.end());
	len=max(len,cnt);
	return res;
}
vector<string>v;
vector<int>ZJY;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		string S=f(a[i]);
		b[i]=S;
	}
	for(int i=1;i<=n;i++) while(b[i].size()!=len) b[i]="0"+b[i]; 
	for(int j=0;j<len;j++){
		int cnt=0;
		for(int i=1;i<=n;i++) if(b[i][j]=='1') cnt++,v.push_back(b[i]);
		if(cnt>=m){
			n=v.size();
			for(int i=1;i<=n;i++) b[i]=v[i-1];
			ZJY.push_back(len-j-1);
		}
		v.clear();
	}
	for(int _:ZJY) ans+=pow(2,_);
	cout<<ans;
	return 0;
}
