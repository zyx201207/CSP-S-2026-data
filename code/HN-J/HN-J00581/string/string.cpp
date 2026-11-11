#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll n,a[N],l,r,sum=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
