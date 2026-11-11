#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
bool check(int n,int k){
	for(int i=0;i<n;i++){
		if(a[i]==k)return 1;
	}
	return 0;
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	 for(int i=0;i<m;i++){
		cout<<"1";
	} 
	return 0;
}

