#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long c[a]= {0},d[a]= {0},hhy=0,mid=a/2+1,l=1,r=a,hy=0,wyx=0;
	for(int i=1; i<=a; i++) cin>>c[i];
	sort(c+1,c+a+1);
	if(c[1]==c[a]) {
		if(a<b) cout<<(a-(b-a*(b%a)))<<endl;
		if(a==b) cout<<a<<endl;
		if(a>b) cout<<b<<endl;
	} else {
		for(int i=1; i<=a; i++) d[i]=c[a]-c[i];
		while(mid!=r) {
			for(int i=l; i<=mid; i++) {
				if(hhy+d[i]-d[mid]<=b) {
					if(hhy+d[i]-d[mid]==b) {
						hy++;
						wyx=1;
						for(int j=mid; j<=a; j++) if(c[j]==c[mid]) hy++;
						cout<<hy<<endl;
						break;
					} else {
						hhy+=d[i]-d[mid];
						hy++;
					}
				} else {
					r=mid;
					mid=(r-l)/2+1;
					hhy=0;
					break;
				}
			}
			if(hhy<b) {
				if((b-hhy)%(mid-l+1)==0) {
					for(int k=mid+1; k<=a; k++) {
						if(c[k]==c[mid]+(b-hhy)/(mid-l)) {
							hy++;
						}
					}
					break;
				}
				l=mid;
				mid+=(r-l)/2+1;
			}
		}
		if(wyx!=1)cout<<hy<<endl;
	}
	return 0;
}