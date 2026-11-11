#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,cnt=0;
long long s[300000];//ÊýÁ¿
long long h[300000];//Î»ÖÃ
char c[300000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>s[i]>>c[i];
		sum+=s[i];
		h[i]=sum;
	}
	long long l=1,r=n,k=1;
	while(l<r) {
		if(c[l]!=c[r]) {
			if((h[l]-k+1)<=(sum-k-h[r-1]+1)) {
				cnt+=(h[l]-k+1);
				k=h[l];
			} else {
				cnt+=(sum-k-h[r-1]+1);
				k=sum-h[r-1];
			}

		}
		k++;
		if(h[l]<k)l++;
		if(h[r-1]>sum-k)r--;
	}
	cout<<cnt;

	return 0;
}
