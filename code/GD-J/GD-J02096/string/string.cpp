#include<bits/stdc++.h>
using namespace std;
bool f;
char a;
int n;
long long cnt;
string s;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	s.resize(n);
	for(int i=0;i<n;i++){
		long long sum;
		cin>>sum;
		char r;
		cin>>r;
		if(!i) a=r;
		if(a!=r) f=1;
		cnt+=sum;
	}
	if(!f) printf("%d",0);
	else cout<<cnt/2;
	return 0;
}
