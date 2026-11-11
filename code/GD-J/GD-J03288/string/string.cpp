#include<bits/stdc++.h>
using namespace std;

int n;
long long num[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	} 
	int i=1,j=n;
	long long m,k1=num[1],k2=num[n],cnt=0;
	for(;i<j;){
		m=min(k1,k2);
		if(c[i]!=c[j])cnt+=m;
		k1-=m,k2-=m;
		if(k1==0)k1=num[++i];
		if(k2==0)k2=num[--j];
	}
	cout<<cnt;
	return 0;
}
