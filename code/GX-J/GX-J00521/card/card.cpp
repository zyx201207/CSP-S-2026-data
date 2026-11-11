#include<bits/stdc++.h>
using namespace std;
int n,m;
int a;
int b=1234567890;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
	}
	for(int i=0;i<m;i++){
		srand(b);
		cout<<rand()<<" ";
	}
	return 0;
}
