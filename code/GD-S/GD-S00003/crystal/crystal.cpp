#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int n,m;
int ans = 1;
int num = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++){
		sort(a + 1,a + 1 + n);
		//num += a[i] + 1;
		a[i] += a[i] + 1;
		num++;
		if(a[i] = a[i + 1]&&num < m){
			a[i + 1] += a[i + 1] + 1;
			num++;
			if(a[i + 1] == a[i + 2]) continue;
		}
		/*if(a[i] = a[i + 1] = a[i + 2]&&num < m){
			a[i + 2] += a[i + 3];
			num++;
		}
		if(a[i] = a[i + 1] = a[i + 2] = a[i + 3]&&num < m){
			a[i + 3] += a[i + 4];
			num++;
		}*/
		if(num == m) break;
		if(a[i] = a[i + 1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*5 5
1 2 4 8 9*/
//Oct31==Dec25?
