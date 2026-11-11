#include<bits/stdc++.h>
using namespace std;
#define int long long
const size_t mn = (size_t)(5e5+100);
int n,m,a[mn],b[mn],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=1;
	while(r<=n){
		while(a[r]*(r-l)-(b[r-1]-b[l-1])<=m && r<=n) r++;
		ans=max(ans,r-l);
		if(r==n+1) break;
		while(a[r]*(r-l)-(b[r-1]-b[l-1])>m) l++;
	}
	printf("%lld",ans);
	return 0;
}
/*
a.py
from random import randint as rd
from os import system
f=open("crystal.in",'w')
n=rd(10**5*4,10**5*5)
m=10**18
f.write(str(n)+' '+str(m)+'\n')
nw=0
for i in range(n):
    f.write(str(nw)+' ')
    nw=rd(-(10**12),10**12)
print(10**12*2/(10**5*5))
print("start")
system("start ./crystal.exe")

b.py
from os import system
for i in range(100):
    system("python a.py")
    f=open("crystal.out","r")
    print(f.readline())
    f.close()
*/
