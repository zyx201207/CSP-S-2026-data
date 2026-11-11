#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
string str="";
for(int i=1;i<=n;i++){
	int a;
	string s;
	cin>>a>>s;
	//for(int j=1;j<=a;j++){
	//	str+=s;
	//}
}
int ans=0;
int m=str.length();
for(int i=0;i<m;i++){
	int u=0;
	u+=i+1;
	if(str[i]!=str[m-u]){
		ans+=1;
		str[m-u]=str[i];
	}
}
cout<<ans;
return 0;
}
