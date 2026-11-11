#include<bits/stdc++.h>
using namespace std;
long long n,len,a[27],sum,col,biglen;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	while(n--){
		cin>>len;
		cin>>c;
		col=c-'a'+1;
		a[col]+=len;
	}
	if(n==1)cout<<0,exit(0);
	sort(a+1,a+1+26);
	for(int i=25;i>=1;i--){
		sum+=a[i];
	}
	cout<<sum;
}
