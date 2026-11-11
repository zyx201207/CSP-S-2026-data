#include<bits/stdc++.h>
using namespace std;
long long n,x,k,ans=0;
char c;
vector<char> u,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=0;j<x;j++){
			s[k+j]=c;
		}
		k+=x;
	}
	long long l=s.size();
	for(int i=l-1,j=0;i>=0;i--,j++){
		u[j]=s[i];
	}
	if(l&1){
		for(long long i=0;i<l/2;i++)
		if(u[i]!=s[i])ans++;
	}else{
		for(long long i=0;i<l/2+1;i++)
		if(u[i]!=s[i])ans++;
	}
	cout<<ans;
	return 0;
}
