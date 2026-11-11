#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0,j=1,len=0;
char l[1000000005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		int nj=j+a[i];
		for(;j<nj;j++){
			l[j] = c[i];
		}
		len+=a[i];
	}
	int size;
	if(len%2 == 0) size=len/2+1;
	else size=len/2;
	for(int i=1;i<=size;i++){
		if(l[i] != l[len-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
