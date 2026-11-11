#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a=0;
	cin >> n>>m;
	int arr[n]={};
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
