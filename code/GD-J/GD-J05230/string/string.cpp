#include<bits/stdc++.h>
using namespace std;
int a[10000005],cnt,ans;
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	cnt=cnt/2;
	int l=1,r=n,mid=(l+r)/2;
	while (ans<=cnt&&l<=mid&&r>=mid){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
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
