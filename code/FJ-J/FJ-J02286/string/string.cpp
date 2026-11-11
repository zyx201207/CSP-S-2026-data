#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200000],total=0,time=0;
	char b[200000],s[200000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(long long j=total;j<total+a[i];j++){
			b[j]=s[i];
		}
		total+=a[i];
	}
	for(long long i=0;i<total/2;i++){
		if(b[i]!=b[total-1-i])time++;
	}
	cout<<time;
	return 0;
} 
