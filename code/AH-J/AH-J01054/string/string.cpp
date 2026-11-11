#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	int i=1,l=n;
	while(i<=l){
		if(a[i]==0){
			i++;
			continue;
		}
		if(a[l]==0){
			l--;
			continue;
		}
		if(c[i]!=c[l]){
			if(a[i]>=a[l]){
				sum+=a[l];
				a[i]-=a[l];
				a[l]=0;
				l--;
			}else{
				sum+=a[i];
				a[l]=a[l]-a[i];
				a[i]=0;
				i++;
			}
		}else{
			if(a[i]>=a[l]){
				a[i]-=a[l];
				a[l]=0;
				l--;
			}else{
				a[l]=a[l]-a[i];
				a[i]=0;
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}

