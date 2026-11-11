#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,l,r;
int a[N];
char c[N];
ll cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]) cnt+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]-=a[l];
			l++;
		}else{
			if(c[l]!=c[r]) cnt+=a[l];
			l++,r--;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
