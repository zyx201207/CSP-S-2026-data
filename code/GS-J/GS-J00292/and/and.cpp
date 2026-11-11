#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],b = -1,an,ts1,ts2,bi = -1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		bi = max(a[i],bi);
	}
	if(m == 1){
		cout << bi;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		an = 0;
		ts1 = a[i];
		for(int k = i + 1;k <= n;k++){
			for(int j = k;j <= k + m;j++){
				if(a[i] == a[j]){
					//cout << 111 << "\n";
					an = a[i];
					continue;
				}
				while(ts1 && ts2){
					an += ts1 & ts2;
					ts1 >>= 1;
					ts2 >>= 1;
				}
			}
			//cout << "an" << "=" << an << "\n";
			b = max(b,an);
		}
	}
	cout << b;
	return 0;
}

