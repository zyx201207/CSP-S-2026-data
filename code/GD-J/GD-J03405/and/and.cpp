#include <bits/stdc++.h>
using namespace std;
long long n,m,d;
long long cnt;
long long b[1000000],c[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int j=0;j<n-m+1;j++){
		cnt = b[j];
		for(int a=0;a<m-1;a++){
			cnt = cnt and b[a+1];
		}
		c[j] = cnt;
	}
	d =c[0];
	for(int s=0;s<n-m+1;s++){
		if(c[s+1]>=c[s]){
			d = c[s+1];
		}
	}
	cout << d;
	return 0;
}
