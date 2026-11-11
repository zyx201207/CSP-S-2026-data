//GZ-S00087 道真仡佬族自治县民族中学 韩诚博 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	for(int i=n-1;i>=0;i--){
		int num=m,num2=1;
		for(int j=i-1;a[i]-a[j]<=num&&j>=0;j--){
			if(a[i]-a[j]<=num){
				num-=a[i]-a[j];
				num2++;
			}
		}
		sum=max(num2,sum);
	}
	cout<<sum;
	return 0; 
}

