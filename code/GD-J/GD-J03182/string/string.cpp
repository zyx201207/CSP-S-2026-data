#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r;
struct node{
	long long sum;
	char v;
}a[200055];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].v;
	}
	l=1,r=n;
	while(l<r){
		if(a[r].v==a[l].v){
			if(a[r].sum<a[l].sum){
				a[l].sum-=a[r].sum;
				r--;
			} 
			else if(a[r].sum>a[l].sum){
				a[r].sum-=a[l].sum;
				l++;
			}
			else if(a[r].sum==a[l].sum){
				l++;
				r--;
			}
		}else{
			if(a[r].sum<a[l].sum){
				a[l].sum-=a[r].sum;
				ans+=a[r].sum;
				r--;
			} 
			else if(a[r].sum>a[l].sum){
				a[r].sum-=a[l].sum;
				ans+=a[l].sum;
				l++;
			}
			else if(a[r].sum==a[l].sum){
				ans+=a[l].sum;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
