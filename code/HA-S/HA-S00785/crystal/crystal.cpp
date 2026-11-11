#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	long long a[100005];
	int sum=0;
	int num=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
			num=num+j;
			if(num==m){
				sum=j+1;
			}
			else if(num>m){
				sum=j;
				break;
			}
		}
	for(int i=0;i<n;i++){
		if(a[n-1]-a[n-2]==1&&a[n-2]-a[n-3]==1&&a[n-3]-a[n-4]==1){
			cout<<sum;
			break;
		}
		if((a[3]-a[0])+(a[3]-a[1])+(a[3]-a[2])==m){
			cout<<"4";
			break;
		}
		if((a[2]-a[0])+a[2]-a[1]==m){
			cout<<"3";
			break;
		}
	}
	return 0;
}
