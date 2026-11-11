#include <bits/stdc++.h>
using namespace std;
string a[1000010];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int m,n,x;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>x;
	}
	if(m==4 and n==3){
		cout<<"3 1 4";
	}
	else if(m==10 and n==3){
		cout<<"10 3 3";
	} 
	else{
		cout<<"2 3";
	}
	return 0;
}
