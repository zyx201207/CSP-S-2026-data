#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long sum=0;
	int l=1,r=n;
	for(;l<=r;){
		if(c[l]!=c[r]){
			if(a[l]<=a[r]){
				sum+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else {
				a[l]-=a[r];
				sum+=a[r];
				a[r]=0;
				r--;
			}
		}
		else {
			if(a[l]<=a[r]){
			    a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else {
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
