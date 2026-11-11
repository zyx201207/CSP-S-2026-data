#include<bits/stdc++.h>
using namespace std;
int n,ma,sum;
long long m,a[500005],m1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i==0){
			ma=1;
			continue;
		}
		m1=m;
		sum=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=m1){
				sum++;
				m1-=a[i]-a[j];
			}
			else{
				break;
			}
		}
		ma=max(ma,sum);
	}
	cout<<ma;
	return 0;
} 
