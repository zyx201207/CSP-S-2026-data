#include<bits/stdc++.h>
using namespace std;
long long n,l=0,r,ans=0;
long long c[200005];
char d[200005];
char f[10000000] ;
int main(){
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		int a=sum;
		for(int j=sum;j<=c[i];j++){
			f[j]=d[i];
			sum++;
		}
	}
	long long z=0;
	for(int i=1;i<=n;i++){
		z+=c[i];
	}
	for(int i=1;i<=z;i++){
		s[i-1]=f[i];
		cout<<s[i-1];
	}
	r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<0;
	return 0;
}
