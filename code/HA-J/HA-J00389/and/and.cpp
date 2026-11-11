#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100];
int maxn=0;
string rjz(int x){
	string y;
	int g=x;
	while(g>=1){
		if(g%2==1){
			y='1'+y;
		}else y='0'+y;
		g/=2;
	}return y;
}
string wy(string s1,string s2){
	string x;
	for(int i=min(s1.length(),s2.length())-1;i>=0;i--){
		if(s1[i]=='1'&&s2[i]=='1'){
			x=x+'1';
		}else x=x='0';
	}
	return x;
}
int sjz(string s1){
	int x=1;
	int ans=0;
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='1'){
			ans+=x;
		}
		x*=2;
	}
	return ans;
}
int hyw(int x,int y){
	return sjz(wy(rjz(x),rjz(y)));
}
int f(int t,int maxm){
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i)
					maxn=max(maxn,hyw(a[i],a[j]));
			}
		}cout<<maxn;
	}
	f(0,0);
	return 0;
}
