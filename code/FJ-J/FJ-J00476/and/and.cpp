#include<iostream>
using namespace std;
int dp[100005],s[100005],n,m,ans,sum,op;
bool use[100005];
void dfs(int a,int choose){
sum++;
	if(choose==m){
	//	cout<<ans<<' ';
		ans=max(a,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a==s[i]||use[i]){continue;
		}
		int b=a;
		a=a&s[i];
		use[i]=1;
		//cout<<a<<' '<<b<<' '<<s[i]<<' ';
		dfs(a,choose+1);
		use[i]=0;
		a=b;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	op=max(op,s[i]);
	}
	if(m==1){
		cout<<op;
		return 0;
	}
	if(m==n){
		int po=s[1];
		for(int i=2;i<=n;i++){
	
	po&=s[i];
	}
	cout<<po;
	return 0;
	}
	
	for(int i=1;i<=n;i++){
		dfs(s[i],1);
	//	cout<<"x"<<' ';
	}
	cout<<ans;
	return 0;}

