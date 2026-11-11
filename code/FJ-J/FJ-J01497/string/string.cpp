#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;

struct str{
	long long a,sum=0;
	char c;	
}s[200003];

char look(long long x) {
	for(int i=1;i<=n;i++){
		if(s[i].sum>=x) return s[i].c;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].sum=s[i-1].sum+s[i].a;
	}
	long long l=1,r=s[n].sum;
	char c1,c2;
	while(l<=r){
		c1=look(l);
		c2=look(r);
		if(c1!=c2) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
