#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=1,r;
	long long ans=0;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(h<r){
		if(c[h]!=c[r]){
			if(a[h]>a[r]){
				a[h]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[h]<a[r]){
				a[r]-=a[h];
				ans+=a[h];
				h++;
			}
			else if(a[h]==a[r]){
				ans+=a[h];
				h++;
				r--;
			}
		}
		else if(c[h]==c[r]){
			if(a[h]>a[r]){
				a[h]-=a[r];
				r--;
			}
			else if(a[h]<a[r]){
				a[r]-=a[h];
				h++;
			}
			else if(a[h]==a[r]){
				h++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
