#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long num;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				num+=a[l];
				a[r-1]-=a[l]-a[r];
			}
			else{
				num+=a[r];
				a[l+1]-=a[r]-a[l];
			}
		}
		l++;
		r--;
	}
	cout<<num;
	return 0;
}
