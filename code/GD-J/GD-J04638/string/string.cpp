#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e7+100;
int a[N],b[N];
char c[N],d[N];
long long ans,sum,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
		d[n-i+1] = c[i];
		b[n-i+1] = a[i];
		sum += a[i];
	}
	int hand1 = 0,hand2 = 0, x=0,y=0;
	long long sum1 = 0,sum2 = 0;
	mid = sum/2;
	for(int i = 1; i <= mid; i++){
		if(i > sum1){
			hand1 = a[++x];
			sum1 += hand1;
		}
		if(i > sum2){
			hand1 = a[++y];
			sum2 += hand2;
		}
		if(c[x] != d[y]) ans++;
	}
	cout << ans;
	return 0;
}
