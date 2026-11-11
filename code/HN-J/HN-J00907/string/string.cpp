#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	long long l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
				
			}
			else{
				a[r]-=a[l];
				l++;
				
			}
			continue;
		}
		else if(a[l]>=a[r]){
			ans+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		else if(a[r]>a[l]){
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
} 
