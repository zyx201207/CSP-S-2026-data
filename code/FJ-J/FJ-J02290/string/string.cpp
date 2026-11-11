#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N][2];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		char c;
		cin >> a[i][0] >> c;
		a[i][1]=c-'a';
	}
	long long ans=0,r=n;
	for(int i=1;i<=r;i++){
		for(int j=r;j>=i;j--){
			if(a[j][0]>a[i][0]){
				if(a[i][1]!=a[j][1]){
					ans+=a[i][0];
					a[j][0]-=a[i][0];
					break;
				}
				else{
					a[j][0]-=a[i][0];
					break;
				}
			}
			else{
				if(a[i][1]!=a[j][1]){
					ans+=a[j][0];
					a[i][0]-=a[j][0];
					r--;
				}
				else{
					a[i][0]-=a[j][0];
					r--;
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
