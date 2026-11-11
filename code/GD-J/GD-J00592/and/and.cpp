#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ma=-1;
string a[200005];
string er(ll x){
	string y,z;
	while(x!=0){
		y+=char(x%2+'0');
		x/=2;
	}
	for(int i=y.size()-1;i>=0;i--){
		z+=y[i];
	}
	return z;
}
ll huan(string x){
	ll y=0;
	for(int i=x.size()-1;i>=0;i--){
		ll yyy=pow(2,x.size()-1-i);
		y+=yyy*(x[i]-'0');
	}
	return y;
}
string yu(string x,string y){
	string z="",zzz="";
	for(int i=x.size()-1;i>=0;i--){
		if(x[i]=='1'&&y[i-x.size()+y.size()]=='1') z+='1';
		else z+='0';
	}
	for(int i=z.size()-1;i>=0;i--){
		zzz+=z[i];
	}
	return zzz;
}
void dfs(ll ge,ll js,string zhi){
	for(int i=ge;i<n;i++){
		string yuu=zhi;
		if(zhi==""){
			zhi=a[i];
		}
		else zhi=yu(zhi,a[i]);
		if(js==m){
			ma=max(ma,huan(zhi));
			return ;
		}
		dfs(i+1,js+1,zhi);
		zhi=yuu;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a[i]=er(x);
	}
	dfs(0,1,"");
	cout<<ma;
	return 0;
} 

