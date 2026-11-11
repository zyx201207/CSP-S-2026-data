#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int cnt=0;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		cnt+=a;
		while(a--)s+=b; 
	}
	int a;
	int ans=0;
	if(cnt%2==1){
		a=(cnt-1)/2;
		for(int i=0;i<=a;i++){
			if(s[a-i]!=s[a+i])ans++;
		}
	}else{
		a=cnt/2-1;
		for(int i=0;i<=a;i++){
			if(s[a-i]!=s[a+1+i])ans++;
		}
	}
	cout<<ans;
}

