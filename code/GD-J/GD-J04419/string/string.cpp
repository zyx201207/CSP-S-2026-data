#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	long long left=a[1],right=a[n],i=1,j=n;
	while(i<j){
		if(left>right){
			if(c[i]!=c[j]){
				sum+=right;
			}
			left-=right;
			right=a[--j];
		}else if(left<right){
			if(c[i]!=c[j]){
				sum+=left;
			}
			right-=left;
			left=a[++i];
		}else{
			if(c[i]!=c[j]){
				sum+=right;
			}
			right=a[--j];
			left=a[++i];
		}
	}
	cout<<sum;
	return 0;
}
