#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
	char qc,hc;
	long long qs=0,hs=0,st=0,en=n+1;
	while(st<en){
		if(qs==0) st++,qs=a[st],qc=c[st];
//		cout<<qs<<" "<<hs<<" "<<qc<<" "<<hc<<" "<<st<<" "<<en<<endl;
		if(hs==0) en--,hs=a[en],hc=c[en];
//		cout<<qs<<" "<<hs<<" "<<qc<<" "<<hc<<" "<<st<<" "<<en<<endl;
		if(st>en) break;
		if(qc==hc) {
			if(qs>hs) qs-=hs,hs=0;
			else hs-=qs,qs=0;
		}else{
			if(qs>hs) ans+=hs,qs-=hs,hs=0;
			else ans+=qs,hs-=qs,qs=0;
		}
//		cout<<qs<<" "<<hs<<" "<<qc<<" "<<hc<<" "<<st<<" "<<en<<endl;
	} 
	cout<<ans;
	return 0;
}  
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
1 v
2 a 

24474

*/
