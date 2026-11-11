#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
string change(long long s){
	string temp="";
	while(s>0){
		temp+=char(s%2+'0');
		s/=2;
	}
	return temp;
}

string opr(string a,string b){
	string ans="";
	
	for(int i=0;i<max(a.size(),b.size());i++){
		if(a[i]!=b[i]) ans+='0';
		else if(a[i]=='0' || b[i]=='0') ans+='0';
		else if(a[i]=='1' && b[i]=='1') ans+='1';
	}
	return ans;
}

long long f(string s){
	long long ans=0;
	for(int i=0;i<s.size();i++){
		ans+=((s[i]-'0')<<i);
	}
	return ans;
}

int n,m;
long long a[MAXN];

long long maxn=-999;
void dfs(int step,int start,string sum){
	if(step==m){
		maxn=(maxn>f(sum)?maxn:f(sum));
		return;
	}
	for(int i=start;i<=n;i++){
		string res=opr(change(a[i]),sum);
		
		if(step==0){
			dfs(step+1,i+1,change(a[i]));
		}
		else{
			dfs(step+1,i+1,res);	
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	dfs(0,1,change(a[1]));
	
	cout<<maxn;

	
	return 0;
}
