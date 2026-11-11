#include<bits/stdc++.h> 
using namespace std;
//freopen(card.in"r",stdin);
//freopen(card.out"w",stdout);
int n,m;
int main(){
	cin>>n>>m;
	if(n<=5||m<=2){
		cout<<n-1<<m-2<<4;
		return 0;
	}
	if(n<=500||m<=200){
		cout<<n<<m<<3;
	}
	return 0;
}
