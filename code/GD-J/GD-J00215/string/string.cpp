#include <bits/stdc++.h>
using namespace std;
string s;
char c[200005];
long long k[200005];
unsigned long long n,cnt,zz1,zz2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	zz1=1;
	zz2=n;
	for(int i=1;i<=n;i++) cin>>k[i]>>c[i];
	while(1){
		if(zz1>=zz2 || (zz1>n || zz2<1)){
			cout<<cnt;
			return 0;
		}
		int minn=min(k[zz1],k[zz2]);
		if(c[zz1]!=c[zz2]) cnt+=minn;
		k[zz1]-=minn;
		k[zz2]-=minn;
		if(k[zz1]==0) zz1++;
		if(k[zz2]==0) zz2--;
	}
	return 0;
}
