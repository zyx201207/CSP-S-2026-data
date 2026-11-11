#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
long long tot=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		tot+=a[i]; 
	}
	long long t=(tot+1)/2;
	int nt=0;
	int l=1,r=n;
	long long lnum=a[l],rnum=a[r];
	char lc=c[l],rc=c[r];
	while(l<r&&nt<=t){
		long long tp=min(lnum,rnum);
		//cout << tp << " ";
		if(lc!=rc) ans+=tp;
		lnum-=tp;
		rnum-=tp;
		nt+=tp;
		if(lnum==0){
			lnum=a[++l];
			lc=c[l];
		}
		if(rnum==0){
			rnum=a[--r];
			rc=c[r];
		}
	}
	cout << ans;
	return 0;
}
