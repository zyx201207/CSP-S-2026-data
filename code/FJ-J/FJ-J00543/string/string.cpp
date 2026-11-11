#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],h,cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
		cin>>c[i];
	}
	h/=2;
	int ii=1,iii=0,jjj=0,jj=n;
	for(int i=1;i<=h;i++){
		if(a[ii]==iii) ii++,iii=0;
		if(a[jj]==jjj) jj--,jjj=0;
		if(c[ii]!=c[jj]) cnt++;
		iii++,jjj++;
	}
	cout<<cnt;
	return 0;
}
