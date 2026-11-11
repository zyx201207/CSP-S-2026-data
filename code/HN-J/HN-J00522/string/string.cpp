#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	int len;
	char a;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>len>>a;
		sum+=len;
		for(int j=1;j<=len;j++){
			s+=a; 
		}
	}
	int ans=0;
	for(int i=0;sum-1-i>=i;i++){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

