#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],a1[200010],ans1,ans2;
char b[200010],b1[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a1[i]=a[i],b1[i]=b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(b[l]!=b[r]){
				ans1+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(b[l]!=b[r]){
				ans1+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(b[l]!=b[r]){
				ans1+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans1;
	
}
