#include<bits/stdc++.h>
using namespace std;
int n;
int a[20000],k;
bool cmp(int o,int p){
	return o>p;
}
string er(int x,string u){
	string f;
	int l=0;
	while(x){
		f+=(char(x%2+'0')!=0&&u[l++]!=0 ? '1':'0');
		x/=2;
	}
	return f;
}
string g(){
	string s,m,ss;
	while(a[1]){
		s+=char(a[1]%2+'0');
		a[1]/=2;
	}
	for(int i=1;i<=k-1;i++){
		string y=er(a[1+i],s);
		s=y;
	}
	return s;
}
long long ji=0,jit=1;
int main(){;
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	string fur=g();
	for(int i=0;i<fur.size();i++){
		ji+=(fur[i]-'0')*jit;
		jit*=2;
	}
	cout<<ji;
	return 0;
} 
/*
Trick||Treat!
*/
