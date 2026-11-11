#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long n,m;
long long a[N];
long long b[N];
long long c[N];
long long sum;
long long y,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i = a[2];i<=a[n];i++){
		for(int x = 1;x<=n;x++){
			if(a[x] <= i){
				c[i] = x;
			}
		}
	}
	for(long long i = a[2];i<=a[n];i++){
		sum = m;
		y = 0;
		for(int x = c[i];x>0;x--){
			sum += a[x];
			b[i]++;
			y++;
			if(sum == i*y){
				break;
			}
			else if(sum < i*y){
				b[i]--;
				break;
			}
		}
	}
	for(long long i = a[2];i<=a[n];i++){
		cout<<b[i]<<" "<<c[i]<<" "<<i<<endl;
		ans = max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}
