#include <bits/stdc++.h>
using namespace std;
long long int n,m,p=0,y=0,k=1,maxx=0,l=0,v=0;
long long int a[500005];
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if (n==1){
		cout<<a[n-1];
		return 0;
	}
	else if (n==m){
		for (int i=0;i<n;i++){
			p=a[i];
			y=0;
			k=1;
			int e=0;
			while (p>0){
				y+=p%2*k;
				k*=10;
				p/=2;	
			}
			a[i]=y;
			cout<<a[i]<<" ";
		}
		maxx=a[0];
		for (int i=1;i<n;i++){
			int t=0;
			l=a[i];
			v=0;
			k=1;
			while (l>0){
				l/=10;
				t++;
			}
			for (int j=0;j<t;j++){
				if (maxx%10==a[j]%10 and maxx%10==1) v+=1*k;
				k*=10;
				maxx/=10;
				a[j]/=10;
			}
			maxx=v;
			cout<<v<<" ";
		}
		v=0;
		k=1;
		while (maxx>0){
			v+=maxx%10*k;
			k*=2;
			maxx/=10;
		}
		cout<<v;
		return 0;
		
	}
	return 0;
}
