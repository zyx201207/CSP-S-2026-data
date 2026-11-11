#include <bits/stdc++.h>
using namespace std;
struct node{
	char c;
	int t;
} d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,tot=-1;
	scanf("%lld",&n);
	string s="";
	for(int i=0;i<n;i++){
		int t;
		char c;
		scanf("%d %c",&t,&c);
		sum+=t;
		d[++tot].c=c,d[tot].t=t;
	}
	long long a=0,t=0,a1=tot,t1=0,ans=0,f=0;
	for(int i=1;;i++){
		if(d[a].t==t) t=0,a++;
		if(d[a1].t==t1) t1=0,a1--;
		if(f==sum/2) break;
		if(d[a].c!=d[a1].c) ans++;
		//cout<<d[a].c;
		t++,t1++,f++;
	}
	cout<<ans;
	return 0;
}
