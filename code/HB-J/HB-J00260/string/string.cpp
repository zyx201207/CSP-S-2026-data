#include<bits/stdc++.h>
using namespace std;
const int L=2e5+5;
long long c=0;
int n;
int a[L];
char b[L];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	int l=0,r=n-1;
	while(l<r){
		if(b[l]!=b[r]) c+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<c;
	return 0;
}
