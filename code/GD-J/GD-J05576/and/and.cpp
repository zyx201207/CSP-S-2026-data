#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j,c,d=0,e,b[31],h=0;
	cin>>n>>m;
	int a[n];
	for(i=0;i<31;i++) b[i]=0;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(i=n-1;i>=0;i--){
		j=0;
		c=a[i];
		while(c){
			j++;
			c/=2;
		}
		if(j<d && b[j]>=m){
			e=1;
			for(j=0;j<31;j++){
				if(b[j]>=m) h+=e;
				e*=2;
			}
			break;
		}
		d=j;
		j=0;
		c=a[i];
		while(c){
			b[j++]+=c%2;
			c/=2;
		}
		
	}
	cout<<h;
	return 0;
}
