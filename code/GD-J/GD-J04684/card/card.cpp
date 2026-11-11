#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],am[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
		am[i]=0;
	}
	for(long long i = 0;i < n;i++){
		long long gm[1000];
		long long gmm=0;
		for(long long j = i;j < n;j++){
			bool che = true;
			long long dx;
			for(long long z = 0;z < gmm;z++){
				if(a[j] == gm[z]){
					che = false;
					dx=z+1;
				}
			}
			if(che){
				gm[gmm] = a[j];
				gmm++;
			}else{
				gmm=dx;
			}
		}
		for(long long j = 0;j < gmm;j++){
			am[gm[j]]++;
		}
	}
	for(long long i = 1;i <= m;i++){
		cout << am[i] << " ";
	}
	return 0;
}


