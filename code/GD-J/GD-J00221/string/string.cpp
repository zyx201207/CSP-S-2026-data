#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;
ll a[200005],s;
char x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	l=1;r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(x[l]!=x[r])s=s+a[l];
			a[r]=a[r]-a[l];
			a[l]=0;
			l++;
		}
		else{
			if(x[l]!=x[r])s=s+a[r];
			a[l]=a[l]-a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<s;
	return 0;
} 
