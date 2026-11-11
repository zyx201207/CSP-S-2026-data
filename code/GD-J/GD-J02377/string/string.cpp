#include <bits/stdc++.h>
using namespace std;

int n,a[200005],c[200005],bl[2000005];
long long len = 0;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int lsid = 1;
	for (int i=1;i<=n;i++) {
		lsid = lsid + a[i-1];
		char ch;
		cin>>a[i]>>ch;
		c[i] = ch - 'a';
		len += a[i];
		fill(bl+lsid,bl+lsid+a[i],c[i]);
	}
//	cout<<'\n';
//	for (int i=1;i<=len;i++) cout<<bl[i];
//	cout<<'\n';
	long long mid = 0,j1 = 0,j2 = 0,cnt = 0;
	if (len % 2 == 1){
		mid = (len/2)+1,j1 = mid-1,j2 = mid+1;
		cnt = 1;
	}
	else {
		mid = (len/2),j1 = mid-1,j2 = mid;
		cnt = 0;
	}
	while (j1 >= 0 && j2<= len) {
//		cout<<"j1:"<<j1<<" bl[j1]:"<<bl[j1]<<" j2:"<<j2<<" bl[j2]:"<<bl[j2]<<'\n';
		if (bl[j1] == bl[j2]) cnt += 2;
		j1--,j2++;
	}
	long long ans = (len - cnt) / 2;
//	cout<<"cnt:"<<cnt<<" ans:"<<ans;
	cout<<ans;
}
