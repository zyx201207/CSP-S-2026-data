#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	int b[10005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];	
	}
	int w=0;
	for(int i=0;i<n;i++){
		if(b[i+1]-b[i]<=m){
			b[i]++;
			if(b[i+1]-b[i]==0){
				b[i]=b[i+1];
				if(b[i]!=a[i]){
					w++;
				}
			}
		}
	}
	cout<<w+1;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
