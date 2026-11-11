#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=1;
	cin>>n;char s[n+5];
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		char b;cin>>b;
		for(int j=num;j<=a+num;j++){
			s[j]=b;
		}
		num+=a;
	}int ans=0;
	for(int i=1;i<=num-1;i++){
		int l=num-i;
		if(s[i]==s[l]){
			continue;
		}else{
			s[l]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
