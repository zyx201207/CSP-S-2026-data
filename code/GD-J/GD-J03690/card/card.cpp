#include<bits/stdc++.h>
using namespace std;
int a[300000];
int b[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);   
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		int x=-1;
		for (int j=i;j<n;j++){
			if (a[j]==b[x] && x!=-1){
				x=0;
				b[0]=a[j];
			}else{
				x++;
				b[x]=a[j];
			}
		}
		cout<<x+1<<" ";
	}
	
} 
