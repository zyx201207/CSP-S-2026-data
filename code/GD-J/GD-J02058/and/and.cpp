#include<bits/stdc++.h>
using namespace std;
string s[200100];
long long n,m,t[200100],ma;
string ef(long long s){
	string t;
	//int k=2;
	while(s){
		int tmp=s%2;
		char c=tmp+'0';
		t=c+t;
		s/=2; 
	}
	return t;
}
string an(string a,string b){
	int s=a.size(),s1=b.size()-a.size();
	string ans;
	for(int i=0;i<s;i++){
		if(a[i]=='1'&&b[i+s1]=='1'){
			ans=ans+'1';
		}else{
			ans=ans+'0';
		}
	}
	return ans;
}
long long fun(string s){
	long long k=1,ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'0')*k;
		k*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i]);
		//cout<<ef(t)<<endl;
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		s[i]=ef(t[i]);
		//cout<<t[i]<<":"<<s[i]<<" ";
	}
	//cout<<endl;
	for(int i=n-m+1;i>=1;i--){
		//cout<<an(s[n-m+1],s[n-m+2])<<endl;
		string t1=an(s[i],s[i+1]);
		ma=max(ma,fun(t1));	
		if(t1==s[i]){
			break;
		} 
	}
	
	cout<<ma;
}
