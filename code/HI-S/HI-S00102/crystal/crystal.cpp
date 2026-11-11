#include <bits/stdc++.h>
using namespace std;
int a[500050]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long x=m,num=0;
		for(int j=i-1;j>=0;j--){
			if(x>=a[i]-a[j]){
				x=x-a[i]+a[j];
				num++;
			}else{
				break;
			}
		}
		sum=max(num,sum);
	}
	cout<<sum+1;
	return 0;
}

