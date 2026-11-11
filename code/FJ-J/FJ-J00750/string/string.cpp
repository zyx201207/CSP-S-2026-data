#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN];
char c[MAXN];
long long pl[MAXN],pr[MAXN];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pl[i]=len+1,pr[i]=len+a[i];
		len+=a[i];
	}
	int il=1,ir=n,nxtl=a[il],nxtr=a[ir];
	long long l=1,r=len,ans=0;
	while (il!=ir and l<r){
		long long tl=l+min(nxtl,nxtr),tr=r-min(nxtl,nxtr);
		if (c[il]!=c[ir]) ans+=tl-l;
		if (nxtl<=nxtr) il++;
		if (nxtr<=nxtl) ir--;
		l=tl,r=tr;
		nxtl=pl[il+1]-l,nxtr=r-pr[ir-1];
	}
	cout<<ans;
	return 0;
}
/*
09:48 WA on Test 5 !
09:52 LONGLONG!!!!! AC
*/
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

6
1 a
1 a
1 a
1 b
1 b
1 b
*/
