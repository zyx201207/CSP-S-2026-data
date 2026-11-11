#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+100;
long long n,ans;
struct Node{
	long long c;
	char x;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,ma = 0;
	scanf("%lld",&n);
	for (i = 1;i <= n;i++){
		scanf("%lld",&a[i].c);
		cin>>a[i].x;
		if (i == 1 || a[i].c > ma) ma = a[i].c;
	}	
	if (n == 1){
		cout<<0<<endl;
		return 0;
	}
	if (ma == 1){
		i = 1;j = n;
		while (i < j){
			if (a[i].x != a[j].x){
				ans++;
			}
			i++;j--;
		}
		cout<<ans<<endl;
		return 0;
	}
	i = 1;j = n;
	while (i < j){
		if (a[i].x == a[j].x){
			if (a[i].c > a[j].c){
				a[i].c -= a[j].c;
				j--;
			}else if (a[i].c < a[j].c){
				a[j].c -= a[i].c;
				i++;
			}else{
				i++;j--;
			}
			continue;
		}
		if (a[i].c > a[j].c){
			a[i].c -= a[j].c;
			ans += a[j].c;
			j--;
		}else if (a[i].c < a[j].c){
			a[j].c -= a[i].c;
			ans += a[i].c;
			i++;
		}else{
			ans += a[i].c;
			i++;j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}