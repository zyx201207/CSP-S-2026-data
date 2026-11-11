#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd();

const int N=5e5+50;

int n,m,a[N];
int pre[N],ans=LLONG_MIN;
bool fg1=1,fg2=1;

int32_t main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=rd();m=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(a[i]!=i) fg1=0;
	}
	if(fg1){
		int s=0;
		for(int i=1;i<=n;i++){
		    s+=a[i];
			if(s>m){
            	printf("%lld",i);
            	return 0;
			}
		}
    }
    sort(&a[1],&a[n+1]);
    int l=0;
	for(int i=2;i<n;i++)
	    if(a[i]-a[i-1]!=a[i+1]-a[i]){
	    	fg2=0;
	    	break;
		}
    if(fg2){
    	int s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) continue;
			l++;
			s+=a[i];
			if(s>m){
            	printf("%lld",l);
            	return 0;
			}
		}
	}
	for(int i=2;i<=n;i++) pre[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int j=i+1,s=0;
		while(j<n){
			s+=(j-i)*pre[j];
			if(s>m) break;
		    j++;
		}
		ans=max(ans,j-i);
	}
	printf("%lld",ans);
	return 0;
}

int rd(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){ if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}

/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

// Oct31==Dec25?
