#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n,a[N];
char c[N];
long long res;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l = 1,r = n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				res += a[l];
			}
			a[r] -= a[l];
			l++;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				res += a[r];
			}
			a[l] -= a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]){
				res += a[r];
			}
			l++,r--;
		}
	}
	cout<<res;
	return 0;
}
