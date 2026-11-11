#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,t=0;
struct node{
	long long a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	int i=1,j=n;
	while(i<j){
		if(s[i].a==0) i++;
		if(s[j].a==0) j--;
		long long x=min(s[i].a,s[j].a);
		if(s[i].c!=s[j].c) t+=x;
		s[i].a-=x;s[j].a-=x;
	}
	cout<<t;
	return 0;
} 
