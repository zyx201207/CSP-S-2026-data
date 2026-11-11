#include<bits/stdc++.h>
using namespace std;
int a[5000005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	long long n,m;
	int i=0;
	long long sum=0;
	cin>>n>>m;
	for(;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	i=0;
	int j=1;
	while(m>0){
		if(a[i]==a[j]){
			if(i==j-1){
				j++;
				i=0;
			}else{
				i++;	
			}
		}else if(a[i]<a[j]){
			a[i]++;
			m--;
		}
	}
	for(int k=0;k<=j+1;k++){
		if(a[k]==a[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
