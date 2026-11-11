#include<bits/stdc++.h>
using namespace std;
struct tt{
	long long num;
	char c;
}a[200100];
long long n,ans,t1,t2,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (long long i=1; i<=n; i++) cin >> a[i].num >> a[i].c;
	t1=1,t2=n;
	while (t1<t2){
		if (a[t1].num<=a[t2].num){
			if (a[t1].c!=a[t2].c) ans+=a[t1].num;
			a[t2].num-=a[t1].num;
		}else{
			sum=0;
			while (sum+a[t2].num<a[t1].num){
				if (a[t2].c!=a[t1].c) ans+=a[t2].num;
				sum+=a[t2].num;
				t2--;
			}
			if (a[t2].c!=a[t1].c) ans+=a[t1].num-sum;
			a[t2].num-=a[t1].num-sum;
		}
		if (a[t2].num==0) t2--;
		t1++;
	}
	cout << ans;
	return 0;
}
