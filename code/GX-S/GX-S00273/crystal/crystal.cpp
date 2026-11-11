#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m;
long long a[N];
long long sum = 0;
int ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / n;
	long long mid = sum -a[1];
	int id = 1;
	for(int i = 1;i <= n;i++){
		if(abs(a[i] - sum) <= mid){
			id = i;
		}
	}
	mid = a[id];
	for(int i = 1;i <= n;i++){
		a[i] = abs(a[i] - sum);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= id;i++){
		if(m - a[i] >= 0){
			ans++;
			m -= a[i];
		}
	}
	for(int i = id+1;i <= n;i++){
		if(m - id *a[id+1] >= 0){
			m -= id * a[id+1];
			id++;
			ans++;
		}else{
			break;
		}
	}
	printf("%d",ans);

}
