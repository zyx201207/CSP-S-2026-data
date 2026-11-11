#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int x;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	long long sum=0;
	for (int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].s;
		sum+=a[i].x;
		for (int j=1;j<=a[i].x;j++){
			s+=a[i].s; 
		}		
	}
	long long sum1=sum;
	long long ans=0;
	sum/=2;
	for (int i=0;i<sum;i++){
		if (s[i]!=s[sum1-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
