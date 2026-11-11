#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct cou{
	long long a;
	char ch;
}e[1000000+250];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>e[i].a>>e[i].ch;
	long long l=0,r=n;
	while(l<=r){
		if(l==r){
			cout<<sum;
			return 0;
		}
		if(e[l].ch!=e[r].ch) sum+=min(e[l].a,e[r].a);	
		if(e[l].a>=e[r].a) e[l].a-=e[r].a,e[r].a=0,r--;
		else e[r].a-=e[l].a,e[l].a=0,l++;
	}
	return 0;
}
