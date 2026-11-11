#include<bits/stdc++.h>
using namespace std;
char c[200001];long long a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l]>=a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
			if(a[l]==0){
				l++;
			}
		}else
		{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}cout<<ans;
	return 0;
}
