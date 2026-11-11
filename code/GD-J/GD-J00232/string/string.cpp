#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a[200005],ans=0,start=0;
	char b[200005];
	bool flag=0;
	cin>>n;
	long long sum=0;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(long long j=start;j<(start+a[i]);j++)s[j]=b[i];
		start+=a[i];
	}
	int l=0,r=sum-1;
	while(l<r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
