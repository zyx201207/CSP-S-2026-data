#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int now[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	int con=0;
	for(int i=0;i<n;++i){
		con=0;
		for(int j=i;j<n;++j){
			for(int k=0;k<con;++k){
				if(now[k]==a[j]){
					con=k;
					break; 
				}
			} 
			now[con]=a[j];
			++con; 
		}
		for(int j=0;j<con;++j){
			b[now[j]-1]+=1;
		}
	}
	for(int i=0;i<m;++i){
		cout << b[i] << ' ';
	}
	return 0;
} 
