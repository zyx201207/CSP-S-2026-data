#include<bits/stdc++.h> 
using namespace std;
const int N=500005;
int n;
long long m,a[N],b[N],c[N],d[N],e[N],da,z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		d[i]=d[i-1]+(i-1)*b[i];
		e[i]=a[i]+e[i-1];
	}
	z=m;
	int j=1,k=1,maxn=0,kk;
	for(int i=2;i<=n;i++){
		if(m<b[i]*k){
			if(i-1>j){
				int l=j+1,r=i-1,mid=(l+r)/2;
				while(l<r){
					mid=(l+r)/2;
					if(d[mid]-d[j]-(j-1)*e[mid]+(j-1)*e[j]>=b[i]*(k-mid+j-1)){
						da=mid;
						r=mid;
					}else{
						l=mid+1;
					}
				}
				m+=d[da]-d[j]-(j-1)*e[da]+(j-1)*e[j];
				k-=(da-j+1);
				j=da+1;
			}
		}
//		cout<<m<<' '<<b[i]*k<<' ';
		if(m>=b[i]*k){
			m-=b[i]*k;
		    k++;
		}
		else{
			j=i;
			k=1;
			m=z;
		}
//		cout<<i-j+1<<' '<<m<<'\n';
		maxn=max(maxn,i-j+1);
	}
	cout<<maxn;
}
//go 14:23
