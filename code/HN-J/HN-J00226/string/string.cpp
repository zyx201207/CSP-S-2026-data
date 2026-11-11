#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10;
ll n,a[N],sum,cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int r=n;
	int l=1;
	while(l+(sum%2)<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r])cnt+=a[l];
			a[r]-=a[l],l++;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r])cnt+=a[r];
			a[l]-=a[r],r--;
		}
		else{
			if(c[l]!=c[r])cnt+=a[l];
			r--,l++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}

