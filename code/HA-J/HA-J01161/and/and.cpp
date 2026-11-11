#include <bits\stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,a1[200005];
string zj(long long x){
	string s="";
	while(x){
		s=char(x%2+'0')+s;
		x/=2;
	}
	return s;
}
int jz(string s){
	long long sum=0,q=1;
	for(int i=s.size()-1;i>=0;i--){
		sum+=q*(s[i]-'0');
		q*=2;
	}
	return sum;
}
int zs(string s){
	long long sum=0;
	for(int i=0;i<s.size();i++){
		sum=sum*10+(s[i]-'0');
	}
	return sum;
}
string y(string x,string y){
	string s="";
	if(x.size()<y.size()){
		string s1=x;
		x=y;
		y=s1;
	}
	//cout<<x<<' '<<y<<"\n";
	long long xz=abs(x.size()-y.size());
	for(int i=y.size()-1;i>=0;i--){
		if(y[i]==x[i+xz]&&y[i]=='1'){
			s='1'+s;
		}else{
			s='0'+s;
		}
	}
	return s;
}
void dfs(long long x,long long d,long long s){
	if(d==n+1){
		if(x==m){
//			for(int i=1;i<=m;i++){
//				cout<<a1[i]<<' ';
//			}
//			cout<<"\n"<<s<<"\n";
			maxx=max(maxx,s);
		}
		return ;
	}
	if(x==m){
		maxx=max(maxx,s);
		return;
	}
	if(x==0){
		a1[x+1]=a[d];
		dfs(x+1,d+1,a[d]);
	}else{
		a1[x+1]=a[d];
		dfs(x+1,d+1,jz(y(zj(s),zj(a[d]))));
	}
	dfs(x,d+1,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout<<jz(y(zj(15),zj(12)));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(0,1,0);
	cout<<maxx;
	return 0;
}

