#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[200005];
int n,m;
bool cmp(string a,string b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	int maxw=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		while(a){
			s[i]=char((a%2)+'0')+s[i];
			a>>=1;
		}maxw=max(maxw,int(s[i].size()));
	}for(int i=1;i<=n;i++){
		int x=maxw-s[i].size();
		for(int j=1;j<=x;j++){
			s[i]='0'+s[i];
		}
	}sort(s+1,s+1+n,cmp);
	int d=0,ans=(1<<30)-1;
	for(int i=1;i<=m;i++){
		d=0;
		for(int j=0;j<maxw;j++){
			
			d=d*2+int(s[i][j]-'0');
		}
		ans&=d;
	}cout<<ans;
	return 0;
}
