#include <bits/stdc++.h>
using namespace std;
long long n=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	long long a[n+10]={};
	char b[n+10]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin >>b[i];
	}
	long long l=1,r=n,re=0,ans=0;
	bool p=0;
	while(l<r){
		if(a[l]>a[r])p=1;
		long long xi=min(a[l],a[r]);
		re=abs(a[l]-a[r]);
		if(b[l]!=b[r])ans+=xi;
		if(re>0){
			if(p){
				a[l]=re;
			}
			else{
				a[r]=re;
			}
	}
		l++;
		r--;
	} 

	cout << ans;
	return 0;
}
