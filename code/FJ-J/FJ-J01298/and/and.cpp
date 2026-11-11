#include<bits/stdc++.h>
using namespace std;
int a[200010];
int cnt;
string change(int x){
	string s,s1;
	while(x>0){
		s+=char(x%2+'0');
		x/=2;
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	return s1;
}
int sw(string s){
	int k=1,ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'0')*k;
		k*=2;				//110
	}
	return ans;
}
int an(string x,string y){
	string s;
	int k=max(x.size(),y.size());
	for(int i=0;i<k;i++){
		if(x[i]=='1'&&y[i]=='1'){
			s+='1';
		}else{
			s+='0';
		}
	}
	return sw(s);
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n,cmp);
	cnt=an(change(a[1]),change(a[2]));
	for(int i=3;i<=m;i++){
		cnt=an(change(cnt),change(a[i]));
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
