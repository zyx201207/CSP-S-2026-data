#include <bits/stdc++.h> 
using namespace std;
string s,sh;
int main(){
	//输入及处理 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	//处理出回文字符串
	for(int i=1;i<=n;i++){
	 	sh[i]=s[n-i]; 
	} 
	for(int i=1;i<=n;i++){
	 	if(sh[i]!=s[n]){
	 		ans++;
		}
	}
	cout<<ans;
	return 0;
}
