#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	ll s,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i]; 
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]) l++,r--;
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]) ans+=a[l],l++,r--;
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

