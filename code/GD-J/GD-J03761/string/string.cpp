#include <bits/stdc++.h>
using namespace std;
int a[200005];
struct ddb {
	long long l,r;
	char fh;
}b[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,jsq=0,ans=0;
	char c;
	string s;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>c;
		sum+=a[i];
		b[i].l=b[i-1].r+1;
		b[i].r=b[i-1].r+a[i];
		b[i].fh=c;
	}
	int i=0,j=0,last=n;
	long long lenl=0,lenr=0;
	long long temp=0;
	if (temp%2==1) temp=sum/2+1;
	else temp=sum/2;
	while (jsq<=temp) {
		i++;
		j=last;
		lenl=sum-b[i].r+1;
		lenr=sum-b[i].l+1;		
		jsq+=a[i];
		if (sum%2&&lenl<=temp) {
			lenl=b[i].r+1;
		}
//		cout<<lenl<<' '<<lenr<<'\n';
//		cout<<i;
		while (b[j].r>=lenl&&i<j) {
//			cout<<j<<'\n';
			if (b[j].l>lenr) {
				j--;
				continue;
			}
			else if (b[j].l>=lenl&&b[j].r<=lenr&&b[i].fh!=b[j].fh) {
				ans+=a[j];
				last=j-1;
			}
			else if (b[j].l<lenl&&b[j].r>=lenl&&b[i].fh!=b[j].fh) {
				if (b[j].r<=lenr) {
					ans+=b[j].r-lenl+1; 
				}
				else {
					ans+=a[i]; 
				}
				last=j;
			}
			else if (b[j].r>lenr&&b[j].l<=lenr&&b[i].fh!=b[j].fh){
				if (b[j].l>=lenl) {
					ans+=lenr-b[j].l+1;
					last=j-1;
				}
				else {
					ans+=a[i]; 
				}
			}
			j--;
		} 
	}
	cout<<ans;
	return 0;
}
