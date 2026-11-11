#include<bits/stdc++.h>
using namespace std;
long long n,sumchange;
struct jilu{
	int l;
	char a;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d %c",&s[i].l,&s[i].a);
		
	long long lid=1,rid=n,mi;
	while(lid<rid){
		mi=min(s[lid].l,s[rid].l);
		if(s[lid].a!=s[rid].a)
			sumchange+=mi;
		s[lid].l-=mi;
		s[rid].l-=mi;
		if(s[lid].l<=0)
			lid++;
		if(s[rid].l<=0)
			rid--;
	}
	cout<<sumchange;
	
	
	
	return 0;
}
