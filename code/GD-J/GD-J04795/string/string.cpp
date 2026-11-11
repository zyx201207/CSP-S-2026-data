#include<bits/stdc++.h>
using namespace std;
const int N=500500; 
int n,a[N];
long long ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	int l=1,r=n;
	while(l<r){
		if(a[r]>a[l]){
			a[r]-=a[l];
			if(c[r]!=c[l])
				ans+=a[l];
			l++;
		}
		else if(a[r]==a[l]){
			if(c[r]!=c[l])
				ans+=a[l];
			l++;
			r--;
		}
		else{
			a[l]-=a[r];
			if(c[l]!=c[r])
				ans+=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
