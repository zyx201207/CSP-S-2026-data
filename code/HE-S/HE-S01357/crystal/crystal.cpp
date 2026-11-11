#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	int n,m,sum=1,max=1,m1;
	cin >>n>>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		m1=m;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=m1&&i>=max){
				sum++;
				m1=m1-(a[i]-a[j]);
			}else{
				break;
			}
		}
		if(sum>max){
			max=sum;
		}
		sum=1;
	}
	cout <<max;
	return 0;
}
