#include<bits/stdc++.h>
using namespace std;
int main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	long long a,b,hhy=0;
	cin>>a>>b;
	long long c[b+1]= {0},d[b+1]= {0};
	for(int i=1; i<=a; i++) {
		cin>>c[i];
		d[c[i]]++;
		hhy=max(hhy,d[c[i]]);
	}
	if(hhy==1) {
		for(int i=a; i>=1; i--) d[c[i]]=i;
		for(int i=1; i<=a; i++) cout<<d[i]<<" ";
		cout<<endl;
	} else {
		long long e[b+1]= {0},g[b+1]= {0},d[b+1]= {0};
		for(int k=1; k<=a; k++) {
			for(int i=k; i<=a; i++) {
				d[c[i]]++;
				if(d[c[i]]==2) {
					for(int j=i; j>=1; j--) {
						if(c[j]!=c[i]) {
							d[c[j]]--;
							if(d[c[j]]<0) d[c[j]]=0;
						} else {
							d[c[j]]=1;
							break;
						}
					}
				}
			}
			for(int i=1; i<=b; i++) e[i]+=d[i];
			long long d[b+1]= {0};
		}
		for(int i=1; i<=b; i++) cout<<e[i]<<" ";
		cout<<endl;
	}
	return 0;
}