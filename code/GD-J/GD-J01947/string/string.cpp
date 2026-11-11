#include<bits/stdc++.h> 
using namespace std;
int n;
long long a[200005];
char c[200005];
string s;
long long gcd_sum;
int sum;
int ans;
int gcd(int x,int y){
	for(int i = min(x,y);i>=1;i--){
		if(x%i==0&&y%i==0){
			return i;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(i==1)gcd_sum=a[i];
		gcd_sum=gcd(gcd_sum,a[i]);
	}
	for(int i = 1;i<=n;i++){
		a[i]/=gcd_sum ;
		sum+=a[i];
		for(int j = 1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l = 0;
	int r = sum-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans*gcd_sum << endl;
	return 0;
}
