#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
long long n,ans[N],sum;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>ans[i]>>a[i];
	}
	long long r=1,l=n-1;
	for(long long i=1;i<=n;i++){
		if(a[r]!=a[l]){
			if(max(ans[r],ans[l])==ans[r]){
				sum+=ans[l];
				ans[r]-=ans[l];
				ans[l]=0;
				if(ans[r]>=1) l--;
				else{
					r++;
					l--;
				}
			}else {
				sum+=ans[r];
				ans[l]-=ans[r];
				ans[r]=0;
				if(ans[l]>=1) r++;
				else{
					r++;
					l--;
				}
			}
		}
	}
	cout<<sum;
	return 0; 
}
