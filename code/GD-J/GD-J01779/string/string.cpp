#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],n,m,k;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				k+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]==a[r]){
				k+=a[l];
				a[l]=0;a[r]=0;
				r--;l++;
			}
			else if(a[l]<a[r]){
				k+=a[l];
				a[r]-=a[l];a[l]=0;
				l++;
			}
		}
		else if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]==a[r]){
				a[l]=0;a[r]=0;
				l++;r--;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];a[l]=0;
				l++;
			}
		}
	}
	cout<<k;
	return 0;
}
