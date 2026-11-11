#include<bits/stdc++.h>
using namespace std;
long long n=0,ans=0,j=0,i,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0;
	string s;
	cin>>n;
	for(i=1;i<=n;i++){
		string s1;
		cin>>j>>s1;
		for(int k=1;k<=j;k++){
			s[num++]=s1[0];
		}
	}
	for(i=0;i<num/2;i++){
		if(s[i]!=s[num-i-1]){
			ans++;
		}
	}
	if(ans==0){
		cout<<"0"<<endl;
	}else{
		cout<<ans;
	}
	return 0;
}
