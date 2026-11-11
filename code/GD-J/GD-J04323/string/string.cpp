#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int n;
long long ans;
long long len;
int c[200005],d[200005];
int b[50000005];
//struct N{
//	long long l;
//	int v;
//}ac[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
//    for (int i=1;i<=n;i++){
//    	cin >> ac.l;
//    	len += ac.l;
//    	char x;
//    	cin >> x;
//    	ac.v=x-'a'+1; 
//    	s[i]=s[i-1]+ac.l;
//	}
//	mid = len/2;
//	for (int i=1;i<=n;i++){
//		if (s[i]>=mid){
//			mid=i;
//		}
//	} 
	for (int i=1;i<=n;i++){
		cin >> a[i];
		len+=a[i];
		char x;
		cin >> x;
		c[i]=x-'a'+1;
		d[i]=d[i-1]+a[i];
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			cnt++;
			b[cnt]=c[i];
		}
	}
//	for (int i=1;i<=len;i++)cout << b[i]<<" ";
    for (int i=1;i<=len/2;i++){
    	if (b[i]!=b[len-i+1]){
    		ans ++;
		} 
	}
    cout << ans;
	return 0;
}
