#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum;
	long long l=1,r=n;
	while(l<r){
		sum+=a[l];
		int j=r;
		while(a[l]-a[j]>0){
			if(a[l]-a[j]>0){
				if(c[j]==c[l]){
					sum-=a[j];
					a[l]-=a[j];
					a[j]=0;
				}
				else{
					a[l]-=a[j];
					a[j]=0;
				}
			}
			else{
				break;
			}
			j--;
		}
		if(c[j]==c[l]){
			sum-=a[l];
		}
		a[j]-=a[l];
		if(a[j]==0){
			j--;
		}
		r=j;
		l++;
	}
	cout<<sum;
	return 0;
}
