#include<bits/stdc++.h>
using namespace std;
long long a[500100],c[500100];
int x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long base=a[i],z=0,sum=0;
		for(int j=0;j<n;j++){
			if(base-a[j]>=0){
				c[z]=base-a[j];
				z++;
			}
		}
		int count1=0;
		for(int j=0;j<z;j++){
			if(sum>m){
				count1--;
				break;
			}
			else{
				sum+=c[j];
				count1++;
			}
		}
		if(count1>x){
			x=count1;
		}
	}
	cout<<x;
	return 0;
} 
