#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+1);
	int max=0;
	for(int i=n;i>=0;i--){
		int cun=m;
		int cun1=0;
		for(int j=0;j<i;j++){
			if(a[i]-a[j]<cun&&a[i]-a[j]>=0&&a[j]!=0){
				a[j]+=(a[i]-a[j]);
				cun-=(a[i]-a[j]);
				cun1++;
			}
			else if(a[j]<0){
				if(a[i]+a[j]<cun&&a[i]+a[j]>=0){
					a[j]+=(a[i]+a[j]);
					cun-=(a[i]+a[j]);
					cun1++;
				}
			}
		}
		if(cun1+1>=max){
			max=cun1+1;
		}
	}
	cout<<max<<endl;
	return 0;
}
