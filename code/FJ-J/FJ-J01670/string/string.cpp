#include<bits/stdc++.h>
using namespace std;
long long a[200005],a2[200005];
char ch[200005],ch2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		ch2[n+1-i]=ch[i];
		a2[n+1-i]=a[i];
	}
	int l=1,r=1;
	long long ans=0;
	while(l!=n+1 || r!=n+1){
		if(ch[l]!=ch2[r]){
			if(a[l]>a2[r]){
				a[l]-=a2[r];
				ans+=a2[r];
				a2[r]=0;
				r++;
			}else if(a[l]<a2[r]){
				a2[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}else{
				ans+=a[l];
				a[l]=0;
				a2[r]=0;
				l++;
				r++;
			}
		}else{
			if(a[l]>a2[r]){
				a[l]-=a2[r];
				a2[r]=0;
				r++;
			}else if(a[l]<a2[r]){
				a2[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				a[l]=0;
				a2[r]=0;
				l++;
				r++;
			}
		}
	}
	cout<<ans/2;
	return 0;
}