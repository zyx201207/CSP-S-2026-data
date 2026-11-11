#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	vector<string>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll x=a[i];
		string t="";
		while(x){
			if(x&1)t+='1';
			else t+='0';
			x>>=1;
		}
		while(t.size()<=30)t+='0';
		s.push_back(t);
	}
	int len=n;
	for(int i=30;i>=0;i--){
		vector<string>tmp;
		for(int j=0;j<len;j++){
			if(s[j][i]=='1'){
				tmp.push_back(s[j]);
			}
		}
		if((int)tmp.size()>=m){
			len=tmp.size();
			s=tmp;
		}
	}
	string tot="";
	for(int i=0;i<=30;i++)tot+='1';
	for(int i=0;i<min(len,m);i++){
//		cout<<s[i]<<"\n";
		for(int j=0;j<=30;j++){
			if(s[i][j]=='0')tot[j]='0';
		}
	}
//	cout<<"\n";
//	cout<<tot<<"\n";
	ll ans=0,k=1;
	for(int i=0;i<=30;i++){
		if(tot[i]=='1'){
			ans+=k;
		}
		k*=2;
	} 
	cout<<ans;
	return 0;
}
