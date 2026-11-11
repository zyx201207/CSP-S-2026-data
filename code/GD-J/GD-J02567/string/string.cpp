#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long c;
	char d;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].c>>s[i].d;
	long long cnt=0,l=1,r=n;
	while(l<r){
		long long m=min(s[l].c,s[r].c);
		if(s[l].d!=s[r].d)cnt+=m;
		s[l].c-=m;
		s[r].c-=m;
		if(s[l].c==0)l++;
		if(s[r].c==0)r--;
	}
	cout<<cnt;
	return 0;
}
