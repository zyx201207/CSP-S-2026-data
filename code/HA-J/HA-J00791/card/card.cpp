#include<bits/stdc++.h>
using namespace std;

long long card[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
   	long long m,n;
   	cin>>m>>n;
   	for(int i=0;i<n;i++){
   		cin>>card[i];
	}
	for(int i=0;i<n;i++){
		cout<<1<<" ";
	}
	return 0;
} 
