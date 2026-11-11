#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,a[2*N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m<=1e5){
		long long a2,l=2*N,r=-2*N;
		for(int i=0;i<n;i++){
			cin>>a2;
			a[a2+N]++;
			l=min(l,a2);
			r=max(r,a2);
		}
		//long long l2=l,r2=r;
		//cout<<l<<' '<<r<<endl;
		long long c=1,c2=0,m2;
		for(int j=l;j<=r;j++){
			//long long mi=(l2+r2)>>1;
			c2=a[j+N];m2=m;
			for(long long i=j+N-1;i>l+N-1;i--){
				if((j+N-i)*a[i]>m2){
					c2+=m2/(j+N-i);m2=0;
					break;
				}
				m2-=(j+N-i)*a[i];
				c2+=a[i];
				//cout<<c2<<' ';
			}
			c=max(c,c2);
			//cout<<c<<endl;
		}
		cout<<c;
	}/*else{
		bool b1=1,b2=1;long long b2i=0;
		cin>>a[1]>>a[2];
		if(a[1]==1 && a[2]==2){
			cout<<min(m,(n*(n-1))>>1)
		}
	}*/
	return 0;
}
