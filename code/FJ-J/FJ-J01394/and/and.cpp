#include<bits/stdc++.h>
using namespace std;
string a[200005];
int n,m;
void er(int x,int y){
	string s="";
	string ss="";
	while(x!=0){
		s+=char(x%2+'0');
		x/=2;
	}
	
	for(int i=0;i<s.size();i++) ss+=s[s.size()-i-1];
	a[y]=ss;
}
string yu(string a,string b){
	if(a.size()<b.size()) {
		string s=a;
		a=b;
		b=s;
	}
	string c=""; 
	int k=a.size()-b.size();
	for(int i=0;i<a.size();i++){
		if(i>=k){
			if(a[i]==b[i-k]&&a[i]=='1') c+='1';
			else c+='0';
		}
		else c+='0';
	}
	return c;
}
int zhi(string s){
	int k=1,ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'0')*k;
		k*=2;
	}
	return ans;
}
int mx=0;
void xuan(int k,int j,string x){
	if(k>m){
		mx=max(mx,zhi(x));
	}
	for(int i=j+1;i<=n;i++){
		if(k==1){
			xuan(k+1,i,a[i]);
		}
		else{
			xuan(k+1,i,yu(x,a[i]));
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		maxx=max(maxx,x);
		er(x,i);
	}
	if(n==m){
		string s=a[1];
		for(int i=2;i<=n;i++){
			s=yu(s,a[i]);
		}
		cout<<zhi(s);
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	xuan(1,0,"");
	cout<<mx;
	return 0;
}
