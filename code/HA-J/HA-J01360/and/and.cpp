#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ma=-1;
int f(int q,int w){
	int e=w,p=q;
	string s1,s2,sx;
	while(p){
		s1=char(p%10)+s1;
		p/=10;
	}
	while(e){
		s2=char(e%10)+s2;
		e/=10;
	}
	if(s2.size()>=s1.size()){
		s2.erase(0,s2.size()-s1.size());
	}else s1.erase(0,s1.size()-s2.size());
	for(int i=0;i<=s1.size();i++){
		if(s1[i]==s2[i]&&s1[i]==1){
			sx+="1";
		}else sx+="0";
	}
	int ss=0;
	for(int i=0;i<sx.size();i++){
		int g=sx[i];
		for(int j=1;j<=sx.size()-i;j++){
			g*=2;
		}
		ss+=g;
	}
	return ss;
}
void dfs(int d,int s,int y){
	if(s==m){
		ma=max(y,ma);
	}
	for(int i=d+1;i<=n-d+1;i++){
		dfs(i,s+1,f(y,a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ma;
	return 0;
}
