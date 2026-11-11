#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,sum,num;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}long long l=0,r=n-1;
	while(l<=r){
		if(b[l]!=b[r]){
			sum+=min(a[l],a[r]);
		}int t=min(a[l],a[r]);
		a[l]-=t;
		a[r]-=t;
		if(a[l]<=0){
			l++;
		}if(a[r]<=0){
			r--;
		}
	}cout<<sum;
}
