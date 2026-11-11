#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,o = 0,q = 0,r = 0;
	cin>>n>>m;
	int a[200005],b[200005],c[200005];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		c[i] = 0;
	//	long long p = 0;
	//	while(a[i] != 0){
	//		p += a[i]*pow(10,o);
	//		o += 1;
	//		a[i] /= 2;
	//	}
	//	a[i] = p;
	//	o = 0;
	}
	//±©Á¦Ã¶¾Ù
	//while(m >= 1){
	//	for(int i = 1;i <= n;i++){
	//	    for(int j = 1;j <= n;j++){
	//			if(i != j){
	//				q = max(q,a[i]&&a[j]);
	//			}
	//		}
	//	}
	//} 
	for(int i = n;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(a[i] > q){
				q = i;
			}
		}
		for(int j = 1;j <= n;j++){
			if(a[j] == q && c[j] == 0){
				b[i] = a[j];
				c[j] = 1;
			}
		}
	}
	cout<<b[m];
	cout<<a.sort();
}
