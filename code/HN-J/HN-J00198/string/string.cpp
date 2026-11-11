#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,temp,r=1,sum=0;
	cin>>n;
	int k=n;
	char d;
	for(int i=1;i<=n;i++){
		cin>>temp>>d;
		if((d-'a'+1)==c[r-1]){
			a[r-1]+=temp;
		}
		else{
			c[r]=d-'a'+1;
			a[r]=temp;
			r++;
		}
	}
	if(r==2){
		cout<<"0";
		return 0;
	}
	r--;
	int l=1;
	while(l!=r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
			}
		}
		else{
			if(a[l]>=a[r]){
				sum+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<sum;
	return 0;
}
