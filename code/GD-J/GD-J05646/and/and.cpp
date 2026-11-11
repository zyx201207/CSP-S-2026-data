#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
string s[N],t;
bool cmp(string x,string y){
	return x>y;
}
string solve(string x,string y){
	string u="";
	for(int i=0;i<30;i++){
		if(x[i]=='1'&&y[i]=='1') u+='1';
		else u+='0';
	}
	return u;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t="";
		while(a[i]>0){
			if(a[i]%2==0) t+='0';
			else t+='1';
			a[i]/=2;
		}
		for(int j=1;j<=t.size();j++){
			s[i]+=t[t.size()-j];
		}
		for(int j=s[i].size();j<30;j++){
			s[i]='0'+s[i];
		}
	}
	sort(s+1,s+n+1,cmp);
	string sum=s[1];
	for(int i=2;i<=m;i++){
		sum=solve(sum,s[i]);
	}
	int ans=0;
	for(int i=0;i<30;i++){
		if(sum[i]=='1') ans=ans+pow(2,29-i);
	}
	cout<<ans;
	return 0;
} 

