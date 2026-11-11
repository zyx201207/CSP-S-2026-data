#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[100000000000];
	long long n,a[10000000000000000],i,j,l=0,s=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int le=0,r=0,g=1,f=n;
	for(i=1;i<=l/2;i++){
		le++;
		r++;
		if(le>a[g]){
			le=le-a[g];
			g++;
		}
		if(r>a[f]){
			r=r-a[f];
			r++;
		}
		if(c[g]!=c[f])
			s++;	
	}
	cout<<s;
	return 0;
}
