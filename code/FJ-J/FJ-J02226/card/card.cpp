#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[60005];
	int c=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		c+=i+1;
		for(int j=1;j<n;j++){
			if(a[i]==a[j]){
				c+=j+1;
			}
		}
		cout<<c<<" ";
		c=0;
	}
	return 0;
}
