#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n;
	cin>>n;
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
