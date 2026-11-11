#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int M=200005;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	int sumn[M];
	char suma[M];
	int s=T;
	int tot=0,ans=0;
	while(T--){
		int n;
		char a;
		cin>>n>>a;
		ans+=n;
		sumn[++tot]=n;
		suma[tot]=a;
	}
	int l,r;
	if(ans%2==0)l=ans/2,r=ans/2+1;
	else l=ans/2,r=ans/2+2;
	int topl=1,topr=s;
	int now=0;
	int cntl=0,cntr=ans;
	while(cntl<=l&&cntr>=r){
		int x=min(sumn[topl],sumn[topr]);
		cntl+=x,cntr-=x;
		if(suma[topl]!=suma[topr])now+=x;
		if(sumn[topl]<sumn[topr])sumn[topr]-=sumn[topl],sumn[topl]=0,topl++;
		else sumn[topl]-=sumn[topr],sumn[topr]=0,topr--;
	}
	cout<<now;
	return 0;
}
