#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*
	long long n,ans=0,sum=0;
	cin>>n;
	int a[n+10];
	char c[n+10];
	for(int i=1;i<=n;i++){
		scanf("%d%c",a[i], c[i]);
		sum+=a[i];
	}
	long long i=1,j=0,k=n,s=sum/2;
	for(;s>0;){
		if(a[i]+j<s){
			if(a[i]<=a[k])
		}
	}*/
	long long n,ans=0,sum=0;
	cin>>n;
	int a[n+10];
	char c[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	long long p=1;
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			b[p]=c[i];
			p++;
		}
	}
	for(long long i=1;i<=sum/2;i++){
		if(b[i]!=b[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
