#include<bits/stdc++.h>
using namespace std;
int a[2*100000+10];
char s[2*100000+10];
long long sum=0;
long long cnt=0;
int MAXN=1e9;
char ans[900000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		for(int j=1;j<=a[i];j++){
			ans[sum+j]=s[i];
		}
		sum+=a[i];
	}
	for(int i=1,j=sum;j>=1;i++,j--){
		if(ans[i]!=ans[j]) cnt++;
	}
	cout<<cnt/2;
	return 0;	
} 
