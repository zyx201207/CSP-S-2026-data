#include <bits/stdc++.h>
using namespace std;

int a[2000005];
char c[2000005];

int n;

long long sum;

int f;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		sum+=a[i];
	}
	long long mid,ans;
	if(sum%2==1){
		mid=(sum+1)/2;
		ans=mid-1;
	}else{
		mid=sum/2;
		ans=mid;
	}
	sum=0;
	int b=n;
	long long x=mid;
	while(x>0){
		f++;
		x-=a[f];
	}
	for(int i=1;i<=f;i++){
		if(c[i]==c[b]){
			if(a[i]<a[b]){
				a[b]-=a[i];
				ans-=a[i];
			}else{
				a[i]-=a[b];
				ans-=a[b];
				b--;
			}
		}
	}	
	cout <<ans;
	return 0;
}
