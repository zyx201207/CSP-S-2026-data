#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	int w=0,z=0;
	while(x){
		if(x%2) w++;
		x=x/2;
	}
	while(y){
		if(y%2) z++;
		y=y/2;
	}
	if(w>=z) return 1;
	return 0;
}
string an(int c){
	string s="";
	while(c){
		s=char(c%2+48)+s;
		c=c/2;
	}
	return s;
}
string f(string x,string y){
	string g="";
	if(x.length()<=y.length()){
		g=x;
		x=y;
		y=g;
	}
	g="";
	for(int i=0;i<y.length();i++){
		if(x[i]=='1'&&y[i]=='1') g=g+'1';
		else g=g+'0';
	}
	return g;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	string s=an(a[1]);
	string h;
	for(int i=2;i<=m;i++){
		h=f(s,an(a[i]));
		if(h>s) s=h;
	}
	long long sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum+(s[i]-48)*pow(2,i);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
