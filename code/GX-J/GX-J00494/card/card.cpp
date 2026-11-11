#include<bits/stdc++.h>
using namespace std;
int n,m;
int js;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	long long i[n],y[n];
	for(int r=0;r<n;r++){
		cin>>i[r];
		}
	int hhh=n;
	while(n>0){
		int u=0;
		if(i[u]<i[u+1]){
			u++;
			}else{
				i[u]=i[u+1];
				}
		n--;
		}
		for(int r=0;r<hhh;r++){
			cout<<y[r];
			}
}
