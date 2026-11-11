#include<bits/stdc++.h>
using namespace std;
int a[200002],c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	scanf("%d",a+i),getchar(),scanf("%c",c+i);
	int ls=0,rs=a[n-1]-1;
	int lg=0,rg=n-1;
	long long ans=0;
	while(lg<=rg&&(lg<rg||ls<rs)){
		if(a[lg]-ls>rs+1){
			if(c[lg]!=c[rg])
			ans+=rs+1;
			//printf("%d,%d:%c %d,%d:%c ans:%d\n",lg,ls,c[lg],rg,rs,c[rg],ans);
			ls+=rs+1;
			--rg;
			rs=a[rg]-1;
		}
		else if(a[lg]-ls==rs+1){
			if(c[lg]!=c[rg])
			ans+=rs+1;
			//printf("%d,%d:%c %d,%d:%c ans:%d\n",lg,ls,c[lg],rg,rs,c[rg],ans);
			++lg;
			ls=0;
			--rg;
			rs=a[rg]-1;
		}
		else{
			if(c[rg]!=c[lg])
			ans+=a[lg]-ls;
			//printf("%d,%d:%c %d,%d:%c ans:%d\n",lg,ls,c[lg],rg,rs,c[rg],ans);
			rs-=a[lg]-ls;
			++lg;
			ls=0;	
		}
	}
	printf("%lld\n",ans);
}
