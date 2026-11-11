#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,snm;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		snm+=a[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			sum+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else if(a[r]>a[l]){
			a[r]-=a[l];
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<min(sum,snm-sum);
	return 0;
}
/*
2
2 a
3 a
*/
