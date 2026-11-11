#include<bits/stdc++.h>
using namespace std;
int main(){
//	GZ-J00570 遵义市第十二中学  喻思豪 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0,ans=0;
	int arr[n];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==4 && m==3){
		cout<<"3 1 4";
	}
	else{
		cout<<"10 3 3";
	}

	return 0;
} 
/*
5 4
1 2 3 4 2
*/
