#include<iostream>
using namespace std;
const int MAXN=2e5+5;

int n;
long long num[27]={0};//每个字母的数量 
long long a[MAXN];//每一段的数量 
char c[MAXN];//字串的字符
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	if(n==1){
		cout<<0;
		return 0;
	}
	
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num[c[i]]+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else ans++;
	}
	cout<<ans;
	
	return 0;
}
