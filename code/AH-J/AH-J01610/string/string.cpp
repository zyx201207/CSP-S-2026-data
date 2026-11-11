#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,L,f=1,l,r;
long long ans;
int a[N];
char c[N];
int main(){
 freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
//  ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
        if(i>1&&c[i]!=c[i-1]) f=0;
   //     cout<<"yes"<<endl;
	}
	if(f){
		cout<<0;
		return 0;
	}
	r=n;
	l=1;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]) l++,r--;
			else{
				if(a[l]>a[r]) a[l]-=a[r],a[r]=0,r--;
				else if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
				else a[l]=a[r]=0,l++,r--;
			}
		}
		else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]) a[l]-=a[r],a[r]=0,r--;
			else if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
			else a[l]=a[r]=0,l++,r--;
		}
	//	cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 
