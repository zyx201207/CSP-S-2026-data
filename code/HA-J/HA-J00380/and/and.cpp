#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a=1,asd=0;
	cin>>n>>m;
	int ass[n];
	for(int i=0;i<n;i++){
		cin>>ass[i];
	}
	for(int i=0;i<n;i++){
		asd=0;
		for(int j=0;j<n;j++){
			if(ass[i]>ass[j]){
				asd=ass[i];
				ass[i]=ass[j];
				ass[j]=asd;
			}
		}
		
	}
	for(int i=1;i<m;i++){
		a=ass[0];
		a=a&ass[i];
	}
	cout<<a;
	return 0;
}
