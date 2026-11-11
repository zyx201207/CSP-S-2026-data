#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,s,d,f,g,h,j=0,k,l;
	cin>>a>>s;
	int w[a+3],e[a+3],r[a+3];
	for(d=0;d<a;d++){
		cin>>w[d];
		e[d]=w[d];
		r[d]=0;
	}
	sort(e,e+a);
	l=e[a-1];
	for(d=0;d<s-1;d++){
		j=0;
		for(f=a-2;f>=0;f--){
			h=l&e[f];
			if(h>=j&&r[f]==0){
				k=f;
				j=h;
			}
		}
		l=l&e[k];
		r[k]=1;
	}
	cout<<l;
	return 0;
}
