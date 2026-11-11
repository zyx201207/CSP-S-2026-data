#include<bits/stdc++.h>
using namespace std;
const long long MAX=150000000;
int n;
long long num;
char inx;
long long x;
long long s[MAX];
long long k,k2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>inx;
		x=inx-'a'+1;
		for(long long j=1;j<=num;j++){
			s[k]=x;
			k++;
		}
	}
	k--;
	if(k%2==0)k2=k/2;
	else k2=k/2+1;
	for(long long i=0;i<k2;i++){
		if(s[i]!=s[k-i])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
