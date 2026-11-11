#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long a[N],sum = 0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l = 1,r = n;
	while(l < r){
		if(a[l] == 0) l++;
		if(a[r] == 0) r--;
		if(c[l] != c[r]){
			sum += min(a[l],a[r]);
		}
		long long mn = min(a[l],a[r]);
		a[l] -= mn;
		a[r] -= mn;
	}
	cout<<sum;
}
