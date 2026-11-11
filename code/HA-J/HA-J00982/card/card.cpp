#include<bits/stdc++.h>
using namespace std;
deque<int> c;
int m,n,a[1000010],b[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int m1[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i-1;j++){
			c.push_back(a[j]);
			if(b[a[j]]){
				while(c.back()!=a[j]){
					c.pop_back();
				}
				c.pop_back();
			}
			else b[a[j]]++;	
		while(c.empty()){
			m1[c.back()]++;
			c.pop_back();
			}		
		}
	}
	for(int l=1;l<=m;l++){
		cout<<m1[l]<<" ";
	}
	return 0;
}
