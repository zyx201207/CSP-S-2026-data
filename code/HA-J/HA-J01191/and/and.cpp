#include <bits/stdc++.h>
using namespace std;
int n,m,op,oi,t;
int w[2005],v[2005];
string a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> w[i];
		int f = w[i];
		while(f>1){
			if(f%2==0){
				a[i]+='0';	
			}
			if(f%2==1){
				a[i]+='1';	
			}
			f=f/2;
			if(f==1){
				a[i]+='1';
				//cout << a[i] << " ";
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].size()>=op&&w[i]>w[oi]){
				op = a[i].size();
				oi = i;
			}
		}
		
	}
	if(m==1){
			cout << w[oi];
		}
	
		
	return 0;
}
