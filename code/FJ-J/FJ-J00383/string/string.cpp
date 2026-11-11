#include<bits/stdc++.h>
using namespace std;
const int n=1e9+10;
char s[n];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0,sum=0;
	char c;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>c;
		for (int j=0;j<a;j++) s[sum+j]=c;
		sum+=a; 
	}
	for (int i=0;i<sum/2;i++){
		if (s[i]!=s[sum-i-1]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
