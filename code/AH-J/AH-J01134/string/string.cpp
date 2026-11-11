#include<bits/stdc++.h>
using namespace std;
const int m=200010;
int n;
int a[m];
char c[m];
long long t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			l++;r--;
			continue;
		}
		else{
			if(a[l]>=a[r]){
				if(c[r-1]==c[l]){
					t+=a[r];
					l++;
					r--;
				}
				else{
					t+=a[l];
					int w=a[l]-a[r],i=r-1;
					while(w>=a[i]){
						w-=a[i];
						a[i]=0;
						i--;
					}
					a[i]-=w;
					r=i;
					l++;
				}
			}
			else{
				if(c[r]==c[l+1]){
					t+=a[l];l++;r--;
				}
				else{
					t+=a[l];
					int w=a[r]-a[l],i=l+1;
					while(w>=a[i]){
						w-=a[i];
						a[i]=0;
						i++;
					}
					a[i]-=w;
					l=i;
					r--;
				}
			}
		}
	}
	cout<<t;
	return 0;
}
