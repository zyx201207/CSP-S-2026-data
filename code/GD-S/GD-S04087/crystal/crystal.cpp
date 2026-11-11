#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int a[n];
	int ans=1;
	int sum=0;
	int averge=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		averge=sum/n;
	}
	int min=averge;
	for(int i=1;i<=n;i++){
		if(a[i]<min){
			min=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++; 
		}
	}
	for(int i=1;i<=n;i++){
		if(m==0){
			break;
			}
		else {
			
		}
	}
	cout<<ans;
	return 0;
} 
