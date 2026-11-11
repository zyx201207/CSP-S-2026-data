#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(int x, int y){
	return x>y;
}

int n, m, a[1000005], z[1000005], c[1000005], k = 1, l = 1;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}sort(a+1, a+n+1, cmp); 
	for(int i = 1;i <= n;i++){
		if(k>m)break; 
		int t = a[i]+1;
		bool f = 1;
		while(t!=0){
			if(t%2==0){
				t/=2;
			}else {
			    f = 0;
				break;
			}
		}if((f == 1)&&k<=m){
			z[k] = a[i];
			k++;
		}else {
			c[l] = a[i];
			l++;
		}
	}if(k<m){
		for(int i = 1;i <= l;i++){
			if(k>m)break;
			z[k] = c[i];
			k++;
		}
	}int sum = z[1];
	for(int i = 2;i < k;i++){
		sum &= z[i];
	}cout<<sum;
	return 0;
}
