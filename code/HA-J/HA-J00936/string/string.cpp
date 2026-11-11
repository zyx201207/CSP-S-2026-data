#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt,n,sum;
void dfs(int j){
	if(j==cnt/2){
		return ;
	}
	if(s[j]==s[cnt-j]){
		dfs(j+1);
	}else if(s[j]!=s[cnt-j-1]){
		
		sum++;
		dfs(j+1);
	}
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char b;
		cin>>b;
		while(a--){
			s[cnt++]=b;
		}
	}
	dfs(0);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
