#include<bits/stdc++.h>
using namespace std;

int n;
int land(int i){
	return rand()%i;
}

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	srand(time(0));
	cout<<land(n);

	return 0;
}

