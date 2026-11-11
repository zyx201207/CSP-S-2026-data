#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=false;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
		if(a[x]>1){
			flag=true;
			
		}
	}
	if(flag==false){
		for(int i=0;i<n;i++){
			cout<<0<<" ";
		}
	}
	return 0;
}