#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,a[500005],h = 1,ans,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1); 
	for (int i = 1;i <= n;i++){
		ans = a[i + 1] - a[i];
		k = ans * h;
		if (m >= k){
			++sum;
			m -= k;
			for (int j = 1;j <= i;j++)
			    a[j] += ans;
			h++;
		}
	}
	cout <<sum;
	return 0;
}
