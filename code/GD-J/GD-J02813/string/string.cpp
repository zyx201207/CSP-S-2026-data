#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		sum+=a[i];
		s[i]=c;
	}
	long long l=0,r=sum,cnt=0;
	while(l<r){
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
