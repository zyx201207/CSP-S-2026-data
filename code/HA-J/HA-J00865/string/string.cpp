#include<bits/stdc++.h>
using namespace std;
char a[100000000000],b;
long long s,n,an,ans1,h,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(long long i=0;i<s;i++){
		cin>>n>>b;
		k=an;
		an+=n;
		for(long long j=k;j<an;j++){
			a[j]=b;
		}
	}for(long long i=0;i<=an/2;i++){
		if(a[i]!=a[an-i-1])ans1++;
	}cout<<ans1;
	return 0;
}
