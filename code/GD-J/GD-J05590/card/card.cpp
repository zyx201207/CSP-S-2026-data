#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int n,m,a[500],c[300],v[300],s;
stack <int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int i=0;i<m;i++){
		fill(v,v+m,0);
		while(!b.empty()) b.pop();
		for(int j=0;j<n;j++){
			for(int k=j;k<n;k++){
				if(v[a[k]]==0){
					b.push(a[k]);
					v[a[k]]=1;
					c[a[k]]++; 
				}
				else{
					while(b.top()!=a[k]) b.pop();
					c[a[k]]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++) cout<<c[i]<<' ';
}
