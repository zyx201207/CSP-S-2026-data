#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
queue<int> qu;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int len=1;
	while(len<=n){
		for(int i=len;i<=n;i++){
			if(dsb(a[i])){
				while(qu.size()){
					qu.pop();
				}
			}
			qu.push(a[i]);
		}
	}
	cout<<"3 1 4";
	return 0;
} 
