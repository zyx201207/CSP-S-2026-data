#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]&&c[l]==c[r]){l++;r--;}
		else if(a[l]==a[r]&&c[l]!=c[r]){
			ans+=a[r];
			r--;
			l++;
		}
		else if(a[l]!=a[r]&&c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else if(a[l]!=a[r]&&c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
