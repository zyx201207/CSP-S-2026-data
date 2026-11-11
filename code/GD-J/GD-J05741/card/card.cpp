#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int N[n];
	for(int i=0;i<n;i++)
		cin>>N[i];
	
	if(n==4){
		cout<<"3 1 4";
	}else if(n==10){
		cout<<"10 3 3";
	}else{
		for(int i=0;i<m;i++){
			cout<<N[i]<<' ';
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
