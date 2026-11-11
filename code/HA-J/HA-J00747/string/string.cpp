#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],s,sum,n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	if(s%2==0){
		while(b[l]<=s/2&&b[r]-a[r]>s/2){
			if(c[l]!=c[r]){
				long long f=min(a[l],a[r]);
				sum+=f;
				a[l]-=f;
				a[r]-=f;
				if(a[r]==0){
					r--;
				}
				if(a[l]==0){
					l++;
				}
			}
		}
		if(l!=r&&c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		else if(l==r){
			sum+=min(b[l]-s/2,a[l]-b[l]+s/2);
		}
		cout<<sum;
		return 0;
	}
	else if(s%2==1){
		while(b[l]<s/2+1&&b[r]-a[r]>s/2+1){
			if(c[l]!=c[r]){
				long long f=min(a[l],a[r]);
				sum+=f;
				a[l]-=f;
				a[r]-=f;
				if(a[r]==0){
					r--;
				}
				if(a[l]==0){
					l++;
				}
			}
		}
		if(l!=r&&c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		else if(l==r){
			sum+=min(b[l]-s/2+1,a[l]-b[l]+s/2+1);
		}
	}
	cout<<sum;
	return 0;
}
