#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
map<long long,long long> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int o=1;o<=n;o++){
		int y=0,k=0;
		for(int i=o+1+k;i<=n;i++){
			y++;
			int f=1;
			for(int j=1;j<=y;j++){
				if(b[j] == a[i]){
					for(int p=j;p<=i;p++){
						b[p]=0;
					}
					y-=i-j;
					f=0;
					k = j;
					break;
				}
			}
			if(f == 0){
				for(int l=1;l<=k;l++){
					a[i]=0;
				}
			}
		}
		for(int d=1;d<=y;d++){
			c[b[d]]++;
		}
	}
	for(auto i:c){
		cout << i.first << " ";
	}
}
