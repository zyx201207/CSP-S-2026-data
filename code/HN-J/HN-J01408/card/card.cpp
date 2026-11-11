#include<bits/stdc++.h>
using namespace std;
int x[500001],y[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
	cin>>x[i];
	y[x[i]]++;
	}
	for(int i=0;i<m;i++){
	if(i==x[n]){
	cout<<n<<" ";
	}else{
	cout<<y[i]<<" ";
	}
	}
	return 0;
} 
