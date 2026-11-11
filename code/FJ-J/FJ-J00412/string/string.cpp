#include<bits/stdc++.h>
using namespace std;
int a[200009];
char c[200009];
long long len1,len,sum[200009],ans,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		len+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	l=1,len1=len/2;
	while(sum[l]<=len1&&l<=n) l++;
	if(sum[l]>len1){
		for(i=n;i>l;i--){
			a[i+1]=a[i];
			c[i+1]=c[i];
		}
		a[l+1]=sum[l]-len1-(len&1);
		c[l+1]=c[l];
		a[l]=len1-sum[l-1];
		n++;
	}
	for(i=l-(len&1),j=l+1;i>=1&&j<=n;){
		if(c[i]==c[j]){
			int tmp1=a[i],tmp2=a[j];
			if(a[i]>=a[j]){
				a[i]-=a[j];
				a[j]=0;
				j++;
			}
			if(a[i]<=a[j]){
				a[j]-=a[i];
				a[i]=0;
				i--;
			}
		}
		else{
			if(a[i]>=a[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j++;
			}
			if(a[i]<=a[j]){
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i--;
			}
		}
	}
	cout<<ans;
	return 0;
}