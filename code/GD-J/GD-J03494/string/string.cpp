#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,a[N],sum,ls,rs,summ,l,r;
char s[N],lz,rz;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	ls=1;
	rs=n;
	lz=s[1];
	rz=s[n];
	while(ls<rs){
		if(lz!=rz){
			if(a[ls]<a[rs]){
				sum+=a[ls];
				a[rs]-=a[ls];
				ls++;
				lz=s[ls];
			}
			else if(a[ls]==a[rs]){
				sum+=a[ls];
				ls++;
				rs--;
				lz=s[ls];
				rz=s[rs];
			}
			else{
				sum+=a[rs];
				a[ls]-=a[rs];
				rs--;
				rz=s[rs]; 
			}
		}
	}
	cout<<sum;
	return 0;
} 
