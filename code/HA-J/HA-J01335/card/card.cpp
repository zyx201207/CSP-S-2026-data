#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,q,p;
int a[N],z[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	z[1] = a[1];
	int rum = 0;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j  <= n;j++){
			if(a[i] != z[j]){
				rum++;
			}
		} 
		if(rum == i){
			z[i] = a[i];
		}
		else{
			for(int i = 1;i <= n;i++){
				
			} 
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<z[i];
	}
	return 0;
}
