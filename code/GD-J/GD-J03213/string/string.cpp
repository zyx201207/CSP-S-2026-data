#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	cin >> n;
	for (long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		l+=a[i];
	}
	if (n==1){
		cout << 0;
		return 0;
	}
	long long last=a[n],now=a[1],i=1,j=n,ans=0;
	while(i<j){
		bool flag=0;
		if (c[i]==c[j]){
			flag=1;
		}
		if (now>=last){
			if (!flag){
				ans+=last;
			}
			now-=last;
			j-=1;
			last=a[j];
		}else{
			if (!flag){
				ans+=now;
			}
			last-=now;
			i+=1;
			now=a[i];
		}
	}
	cout << ans;
	return 0;
}
//aabbc
//cbbaa
//
