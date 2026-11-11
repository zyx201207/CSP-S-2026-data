#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	string c[n];
	int sum=0;
	string b[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i+1]){
			cout<<"0";
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=n;j>0;j--){
			while(a[i]>0){
				b[i]=c[i]+c[i];
				a[i]-=2;
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
