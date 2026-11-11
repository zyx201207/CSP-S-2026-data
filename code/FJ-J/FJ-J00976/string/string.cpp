#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	const int N=2e5+5;
	long long n,a[N],k=0,ans=0,l,r;
	char c[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	if(k%2==0){
		k/=2;
	}
	else{
		k-=1;
		k/=2;
	}
	l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				}
				else{
					if(a[l]==a[r]){
					l++;
					r--;
					}	
				}
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				if(a[l]<a[r]){
					ans+=a[l];
					a[r]-=a[l];
					l++;
				}
				else{
					if(a[l]==a[r]){
						ans+=a[l];
						l++;
						r--;
					}	
				}	
			}
		}
	}
	cout<<ans;
	return 0;
}
