//李杜文谦 GZ-J00407 清镇市广大实验学校
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+15;
char s[N];
int a[N];
int n,m,l,r,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i]; 
	}
	l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				s[r]=s[l];
				r--;
			}else{
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				s[l]=s[l];
				l++;
			}
		}else if(a[l]>a[r]){
			r--;
		}else if(a[l]<a[r]){
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;	
}
