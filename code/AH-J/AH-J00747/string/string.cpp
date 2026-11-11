#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	unsigned long long s=0;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>b[i];
	long long l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				s+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				s+=a[l];
				l++;
				r--;
			}
		}
		else {
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}
