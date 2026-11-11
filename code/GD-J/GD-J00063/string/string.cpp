#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],s=0;
int n;
char c[N];
int main(){
	freopen ("string6.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i+=1){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while (l<=r){
		if (a[l]>a[r]){
			if (c[l]!=c[r]){
				s+=a[r];
			}
			a[l]-=a[r];
			r-=1;
		}
		else if(a[l]<a[r]){
			if (c[l]!=c[r]){
				s+=a[l];
			}
			a[r]-=a[l];
			l+=1;
		}
		else {
			if (c[l]!=c[r]){
				s+=a[l];
			}
			l+=1;
			r-=1;
		}
	}
	cout<<s;
	return 0;
}
