#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
const int M=3e5+10;
long long n,m;
long long a[N],ton[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ton[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(ton[i]!=0){
			cout<<ton[i]<<" ";
		}
	}
	return 0;
}
