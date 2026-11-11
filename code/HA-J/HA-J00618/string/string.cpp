#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010;
struct node{
	int l,r;
	char c;
}a[N],k[N];
int ans,n;
int k1;
int len;
char k2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> k1 >> k2;
		len+=k1;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+k1-1;
		a[i].c=k2;
	}
	for(int i = 1; i <= n; i++){
		k[i].l=len-a[n-i+1].r+1;
		k[i].r=len-a[n-i+1].l+1;
		k[i].c=a[n-i+1].c;
	}
	int l1=1,l2=1;
	while(1){
		if(a[l1].c==k[l2].c)ans = ans+min(a[l1].r,k[l2].r)-max(a[l1].l,k[l2].l)+1;
		if(l1==n&&l2==n)break;
		if(a[l1].r==k[l2].r)l1++,l2++;
		else if(l1!=n&&a[l1+1].l<=k[l2].r)l1++;
		else if(l2!=n&&k[l2+1].l<=a[l1].r)l2++;
	}
	cout << (len-ans)/2;
	return 0;
}
/*

*/
