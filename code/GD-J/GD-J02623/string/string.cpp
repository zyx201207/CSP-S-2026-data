#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	long long sum=0;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>=a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
				
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
