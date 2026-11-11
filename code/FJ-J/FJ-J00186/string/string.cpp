#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i]>> c[i];
	}
	bool f=1;
	long long r=n,l=1;//l表示左边的下标，r表示右边的下标 
	long long ans=0;
	while(l<=r){
		long long o=a[l],oo=c[l];
		long long b=a[r],bb=c[r];
		if(oo==bb){
			if(o>b){
				r--;
				a[l]=o-b;
			}
			else{
				l++;
				a[r]=b-o;
			}
		}
		else{
			if(o>b){
				c[r]=c[l];
				r--;
				a[l]=o-b;
				ans+=b;
			}
			else{
				c[l]=c[r];
				l++;
				a[r]=b-o;
				ans+=o;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

5
2 a
4 b
2 c
1 d
5 e
*/
