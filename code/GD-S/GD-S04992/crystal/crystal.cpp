#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,sum=0;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> total(n,0);	
	vector<int> gap(n,0); 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=1;i<n;i++){
		gap[i]=a[i]-a[i-1];
	}
	if(m==0){
		for(int i=0;i<n;i++){
			total[a[i]]++;
		}
		for(int i=0;i<a[n];i++){
			if(sum<total[i]){
				sum=total[i];
			}
		}
		cout<<sum;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}	
	if(n==2){
		if(a[0]+m>a[1]||a[0]+m==a[1]){
			cout<<2;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
