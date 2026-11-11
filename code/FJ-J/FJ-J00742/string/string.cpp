#include<bits/stdc++.h>
using namespace std;
char s[299999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a;
	char c;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			l++;
			s[l]=c;
		}
	}
	long long sum=0;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
