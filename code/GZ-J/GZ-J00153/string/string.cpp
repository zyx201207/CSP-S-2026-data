//GZ-J00153,遵义市第十九中学,刘婧妍。
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(long long j=1;j<=a[i];j++){
			s=s+b[i];
		}
	}
	int x=s.size();
	for(int i=0;i<(x+1)/2;i++){
		if(s[i]!=s[x-i-1]){
			sum++;
		}
	}cout<<sum;
	return 0;
}
