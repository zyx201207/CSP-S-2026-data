#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,a[N],num;
char b[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]==a[r]) l++,r--;
			else if(a[l]<a[r]) a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		else{
			if(a[l]==a[r]){
				num+=a[l];
				l++,r--;
			}
			else if(a[l]<a[r]){
				num+=a[l];
				a[r]-=a[l],l++;
			}
			else{
				num+=a[r];
				a[l]-=a[r],r--;
			}			
		}
	}
	cout<<num;
	return 0;
}
