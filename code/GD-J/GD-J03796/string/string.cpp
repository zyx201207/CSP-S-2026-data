#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ci;
		cin>>a[i]>>ci;
		c[i]=ci-'A';
	}
	long long r=1,l=n,ri=1,li=a[n];
	long long sum=0;
	while(1){
		long long m=min((a[r]-ri+1),(li-0));
		if(r==l) m=min(m,(li-ri-1)/2);
		if(c[r]!=c[l])  sum+=m;;
		ri+=m,li-=m;
		if(ri>a[r]){
			r++;
			ri=1;
		}
		if(li<1){
			l--;
			li=a[l];
		} 
		if((l==r && (li-ri)<=2) || (r-l==1 && li==a[l] && ri==1)){
			break;
		} 
	}
	cout<<sum;
	return 0;
}
