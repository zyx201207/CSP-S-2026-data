#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,sssss=0;
	cin>>n;
	int a[n+1],a1[n+1];
	string b[n+1],b1[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		a1[n-1-i]=a[i];
		b1[n-1-i]=b[i];
	}
	string S="",s="";
	for(int i=0;i<n;i++)for(int j=0;j<a[i];j++)S+=b[i];
	for(int i=0;i<n;i++)for(int j=0;j<a1[i];j++)s+=b1[i];
	for(int i=0;i<sum;i++){
		cout<<S[i]<<' '<<s[i]<<endl;
		if(S[i]!=s[i])sssss++;
	}
	cout<<sssss/2;
	return 0;
}
