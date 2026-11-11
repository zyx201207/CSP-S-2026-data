#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000005],maxx=-1,v;
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(i!=j){
				v=a[i] and a[j]; 
				maxx=max(maxx,v); 
			} 
		} 
	}cout << maxx; 
	return 0;
}
