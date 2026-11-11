#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char b[200001];
long long int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int l=0;
	for(int i=1;i<=n;i++){
		int a2;
		char b2;
		cin>>a2>>b2;
		if(b2==b[l]){
			a[l]+=a2;
		}
		else{
			l++;
			a[l]=a2;
			b[l]=b2;
		}
	}
	int left=1,right=l;
	while(left<right){
		if(b[left]==b[right]){
			if(a[left]<a[right]){
				left++;
				a[right]-=a[left];
			}
			else if(a[left]==a[right]){
				left++;
				right--;
			}
			else{
				right--;
				a[left]-=a[right];
			}
		}
		else{
			if(a[left]<a[right]){
				ans+=a[left];
				left++;
				a[right]-=a[left];
			}
			else if(a[left]==a[right]){
				ans+=a[left];
				left++;
				right--;
			}
			else{
				ans+=a[right];
				right--;
				a[left]-=a[right];
			}
		}
	}
	cout<<ans;
	return 0;
}
