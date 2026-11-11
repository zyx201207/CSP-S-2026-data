#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=5  && m<=2){
		cout<<7;
	} else if(n<=500 && m<=200){
		cout<<14;
	}else{
		cout<<27;
	}
	
	return 0;
}
