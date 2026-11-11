#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
long long q[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long len=0;
	memset(q,0,sizeof(q));
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q[i]=q[i-1]+a[i];
		len+=a[i];
	}
	long long mid;
	if(len%2==0)mid=len/2;
	else mid=len/2+1;
	long long l=1,r=len;
	int il=1,ir=n;
	long long ans=0;
	while(l<mid&&r>mid){
		//cout<<c[il]<<" "<<c[ir]<<endl;
		if(c[il]!=c[ir]){
			ans++;
		}
		l++;
		r--;
		if(l>q[il])il++;
		if(r<q[ir-1])ir--;
	}
	cout<<ans<<endl;
	return 0;
}
//Trick||Treat!
/*
2 1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
/*
5
3 a
4 b
5 c
6 d
7 a
*/
