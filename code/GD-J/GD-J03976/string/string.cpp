#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
long long n,x[N];
char a[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long cnt = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		if(a[i] == a[i-1]){
			x[i-1] += x[i];
			i--;n--;
		}
	}
	if(n == 1) {
		cout<<0;
		return 0;
	}
	if(n == 2){
		cout<<min(x[1],x[2]);
		return 0;
	}
	for(int i=1;i<=n/2+(n%2);i++){
		if(i == n/2+n%2 and n > 2) {
			if(x[i] < 0) cnt += x[i];
			else if (x[i]%2!=0 and x[i]!=1) cnt++;
			continue; 
		}
		cnt += max(x[i],x[n-i+1]);
		if(x[n-i+1] > x[i]) x[i+1] -= x[n-i+1]-x[i];
		if(x[i] > x[n-i+1]) x[n-i] -= x[i]-x[n-i+1];
	}                          
	cout<<cnt;
	return 0;
}
