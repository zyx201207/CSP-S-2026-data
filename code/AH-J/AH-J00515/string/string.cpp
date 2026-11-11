#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001];
long long num;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				num+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[r]>a[l]){
			if(c[l]!=c[r]){
				num+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else{
			if(c[l]!=c[r]){
				num+=a[l];
			}
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
	}
	cout<<num;
	return 0;
}
