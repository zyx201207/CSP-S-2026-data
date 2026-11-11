#include <bits/stdc++.h>
using namespace std;
struct node{
	int sum;
	char value;
}a[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].sum>>a[i].value;
	int l=1,r=n;
	while(l<r){
		if(a[l].sum==a[r].sum){
			if(a[l].value!=a[r].value) ans+=a[l].sum;
			l++;
			r--;
		}
		else{
			if(a[l].value!=a[r].value){
				ans+=min(a[l].sum,a[r].sum);
			}
			if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				r--;
			}
			else{
				a[r].sum-=a[l].sum;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
