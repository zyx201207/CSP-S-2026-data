#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ans=0;
	if(n==1){
		printf(0);
		return 0;
	}
	int l=1,r=n;
	int a[n+3];
	char b[100];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
		 if(a[l]>=a[r]){
			a[l]-=a[r];
			ans+=a[r];
			a[r]=0;
		 }
		 else{
			a[r]-=a[l];	
			ans+=a[l];
			a[l]=0;
			
	     }
       } 
	}
	printf("%d",ans);
	return 0;
}
