#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt,cnta;
char c[200005];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnta+=a[i];
	}
	long long h=cnta/2;
	int p=1;
	for(long long i=1;i<=h;i++){
		s1+=c[p];
		a[p]--;
		if(!a[p])p++;
	}

	p=n;
	int h1=(cnta%2==1)?h+1:h;
	for(long long i=cnta;i>h1;i--){
		s2+=c[p];
		a[p]--;
		if(!a[p])p--;
	}
	
	for(long long i=0;i<h;i++){
		if(s1[i]!=s2[i])cnt++;
	}
	cout<<cnt;
}
