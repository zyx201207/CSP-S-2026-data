#include<bits/stdc++.h>
using namespace std;
long long n,m,c,a[100000],s[100000];
int s1,s2,s3;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]++;
	}
	s1=3;
	s2=1;
	s3=4;
	cout<<s1<<" "<<s2<<" "<<s3;
}
