#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
string y;
string z(int x){
	int y=1;
	string s;
	while(y<x){
		y*=2;
	}
	while(x>0){
		if(y<=x){
			x-=y;
			s+="1";
			y/=2;
		}
		else s+='0';
	}
	return s;
}
string yu(string a,string b){
	string s,x;
	if(a.size()<b.size()) swap(a,b);
	s=a;
	int i=a.size()-1,j=b.size()-1;
	while(i>0){
		if(a[i] && b[j]) s[i]='1';
		else s[i]='0';
		i--;
	}
	return s;
}
string a[200005],f[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=z(x);
	}
	//sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			y=yu(a[i],a[j]);
			if(y>f[2]) f[2]=y;
			
		}
	}
	for(int i=3;i<=m;i++){
		for(int j=1;j<=n;j++){
			y=yu(a[j],f[i-1]);
			if(y>f[i]) f[i]=y;
		}
	}
	int ans=0,y=1;
	for(int i=f[m].size()-1;i>=0;i--){
		ans+=y*int(f[m][i]-'0');
	}
	cout<<ans;
	return 0;
}
