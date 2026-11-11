#include<bits/stdc++.h>
using namespace std;
int a[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,ans=0;
	char ch;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>ch;
		sum+=a[i];
		a[i]=a[i-1]+a[i];
		for(int j=a[i-1];j<a[i];j++){
			s[j]=ch;
		}
	}
	if(sum%2==0){
		for(int i=0;i<sum/2;i++){
			if(s[i]!=s[sum-1-i]) ans++;
		}
	}else{
		for(int i=0;i<sum/2+1;i++){
			if(s[i]!=s[sum-1-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
