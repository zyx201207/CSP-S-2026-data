#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,m;
	string c={},c1={},c2;
	cin>>n>>m;
	int a[n+5]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}	
	}
	int max1=0;
	for(int i=0;i<m;i++){
		int a1=a[i];
		while(a1){
			if(a1%2==0){
				c+='0';
				a1/=2;
			}
			else{
				c+='1';
				a1/=2;
			}
		}
		for(int j=0;j<17;j++){
			if(c[j]==c1[j]==49){
				c1[j]='1';
			}
			else{
				c1[j]='0';
			}
		}
		c2=c1;
		c1=c;
		c={};
		int sum=0;
		for(int j=0;j<17;j++){
			if(c1[j]=='1'){
				sum=sum+pow(2,j);
			}
		}
		max1=sum;
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
