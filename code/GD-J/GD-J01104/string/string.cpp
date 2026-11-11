#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=2e5+1;

int n;
ll L;
ll half;
ll a[N];
ll ans;
char c[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	if(n==1) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	half = L/2;
	//改前一半i为后一半 j
	ll cnt=0;
	int i=1,j=n;
	while(cnt <= half && i <= j) {
		if(a[i] == a[j]) {
			if(c[i] == c[j]) {
				j--; i++;
			}
			else {
				cnt += a[i];
				j--; i++;
			}
		}
		else if(a[i] > a[j]) {
			if(c[i] == c[j]) {
				a[i] -= a[j];
				j--;
			}
			else {
				cnt += a[j];
				a[i] -= a[j];
				j--;
			}
		}
		else { // a[j] > a[i]
			if(c[i] == c[j]) {
				a[j]-=a[i];
				i++;
			}
			else {
				cnt += a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
