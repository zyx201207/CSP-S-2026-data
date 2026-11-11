#include<bits/stdc++.h>
using namespace std;
int a[200000];
char s[9000000000];
char b[200000];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	int m=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s[m]=b[i];
			m++;
		}
	}
	int ans=0;
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	} 
	cout<<ans;
}
