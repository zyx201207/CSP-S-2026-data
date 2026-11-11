#include <bits/stdc++.h>
using namespace std;
int m,n,x[300002]={0},j=0;
string a;
string b="0";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		while(j<n){
			if(b.find(a[j])){
				b=a[j];
				
			}else{
				b+=a[j];
			
			}
			
			j++;
		}
		cout<<b<<" ";
		j=0;
		for(int z=46;z<m+46;z++){
			if(b.find(char(z))){
				x[z-45]++;
				
			}
		}
		b="0";
		a[i]='0';
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
