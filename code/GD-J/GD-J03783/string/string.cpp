#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct str{
	long long a;
	char c;
}s[N];

long long n,l,r,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	l=1;r=n;
	while(l<r){
		long long x=s[l].a,y=s[r].a;
		if(s[l].c!=s[r].c){
			ans+=min(x,y);
		}
		s[l].a-=y;s[r].a-=x;
		if(s[l].a<=0){l++;}
		if(s[r].a<=0){r--;}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
