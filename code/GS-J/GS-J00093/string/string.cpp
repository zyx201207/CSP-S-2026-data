#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1||i==n||i==n/2+1||j==n||j==n-1){
				cout<<"7";
			}
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(i<8){
			cout<<i/2+1;
		}
		else{
			cout<<i;
			n++;
		}
		
	}

	return 0;
}
