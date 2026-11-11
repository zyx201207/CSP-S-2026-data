#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int c;
int n,d,ans;
int a[1000005];
int b[1000005];
int l[1000005];
int r[1000005];
int lx[1000005],rx[1000005],tot;
void f(){
	ans=0;tot=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=l[i]=r[i]=0;
		lx[i]=rx[i]=0; 
	}
	a[n+1]=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		b[i]=ans;
	}
	int sum=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<=d){
			sum++;
		}else{
			sum=0;
		}
		l[i]=sum;
	}
	sum=0;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]-a[i]<=d){
			sum++;
		}else{
			sum=0;
		}
		r[i]=sum;
	}
	int last=1;
	for(int i=1,j=1;i<n;i=j){
		int r1=b[i],r2=-1,l1=i;
		if(r1==0||r1==i+1){
			j=i+1;
			continue;
		}
		if(b[r1-1]!=b[r1-2]&&b[r1-1]!=0){
			int l=r1+1,r=b[r1-1],ans=b[r1-1];
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[r1-2]>d){
					r=mid-1;
					ans=mid;
				}else{
					l=mid+1;
				}
			}
			
			r2=ans;
			l=i,r=r1-2,ans=r1-2;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[r1+1]-a[mid]>d){
					l=mid+1;
					ans=mid;
				}else{
					r=mid-1;
				}
			}
			l1=ans;
		}
		if(r2==-1){
			j=i+1;
			continue;
		}
		lx[++tot]=l1;
		rx[tot]=r2;
//		cout<<i<<" : "<<"add "<<lx[tot]<<" "<<rx[tot]<<"\n";
		j=l1+1;
		if(tot==1)continue;
		ans+=min(l[lx[tot-1]]+1,lx[tot-1]-(lx[tot-2]+1)+1)*min(r[rx[tot-1]]+1,rx[tot]-1-rx[tot-1]+1);
//		cout<<i<<" : "<<min(l[lx[tot-1]]+1,lx[tot-1]-(lx[tot-2]+1)+1)<<" "<<min(r[rx[tot-1]]+1,rx[tot]-1-rx[tot-1]+1)<<"\n";

	}
	ans+=min(l[lx[tot]]+1,lx[tot]-(lx[tot-1]+1)+1)*(r[rx[tot]]+1);
//	cout<<n+1<<" : "<<min(l[lx[tot]]+1,lx[tot]-(lx[tot-1]+1)+1)<<' '<<r[rx[tot]]+1<<"\n";
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
//	freopen("migrate6.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--)
	f();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

0 1
6 4
999999999999999993 999999999999999994 999999999999999995 999999999999999996 999999999999999997 1000000000000000000

*/
