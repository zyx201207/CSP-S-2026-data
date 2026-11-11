#include<bits/stdc++.h>
using namespace std;
struct aaa{
	unsigned long long x;
	char b;
}a[200005];
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		cin>>a[i].b;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].b==a[r].b){
			if(a[l].x==a[r].x){
				l++;r--;
			}else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				l++;
			}
		}else if(a[l].b!=a[r].b){
			if(a[l].x==a[r].x){
				ans+=a[l].x;l++;r--;
			}else if(a[l].x>a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
