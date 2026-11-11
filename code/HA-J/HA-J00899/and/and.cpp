#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
string ass[100005];
string  zl(int k){
	string s;
	while(k>0){
		s+=(k%2)+'0';
		k/=2;
	}
	return s;
}
int zs(string s){
	reverse(s.begin(),s.end());
	int cnt=0;
	for(int i=0;i<s.size();i++){
		cnt+=(s[i]-'0')*pow(2,(s.size()-i-1));
	}
	return cnt;
}
string kk(string s1,string s2){
	string s3;
	for(int i=0;i<min(s1.size(),s2.size());i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			s3=s3+"1";
		}
		else{
			s3=s3+"0";
		}
	}
	return s3;
}
void dfs(int c,string s,int k){
	if(k==m){
		maxx=max(zs(s),maxx);
		return ;
	}
	for(int i=c;i<=n;i++){
		int l=k+1;
		if(k==0){
			dfs(i+1,ass[i],l);
		}
		else{
			dfs(i+1,kk(s,ass[i]),l);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		ass[i]=zl(a);
	}
	dfs(1,"",0);
	cout<<maxx;
	return 0;
}

