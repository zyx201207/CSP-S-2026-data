#include<bits/stdc++.h>
using namespace std;

int a[200005];char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,u=1;
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	} 
	int min=a[1];
	for (int i = 2;i<=n;i++){
		if (b[i-1]!=b[i]) u=0;
		//cout << (b[i-1]!=b[i]) << endl << u << endl;
		//if (a[i]>min) min=a[i];
	}
	long long cnt=0;

		for (int i = 1,j = n;i<=n/2&&j>n/2;i++,j--){
			int h=(b[i]==b[j]);
			//cout << h << endl;
			if (h==0) {
				if (a[i]>=a[j]){
					cnt+=a[i];
				}
				else cnt+=a[j];
			}
		}
	if (u==1) cout << 0;
	else cout << cnt;
	return 0;
} 
