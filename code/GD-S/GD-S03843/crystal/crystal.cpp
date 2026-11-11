#include<bits/stdc++.h> 
using namespace std;
int main(){
	/*
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	*/
	int n=0,a[10086],m=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	int b[10086],c=0;
	int p=0;
	for(int i=0;i<=n;i++){
		b[i]=a[i];
		for(int j=0;j<=m;i++){
			if(b[i]==a[j]){
				c=b[i];
			}else{
				c=0;
			}
			
			if(c==0){
				cout<<"3";
				return 0;
			}else{
				while(a[c-1]==c){
					a[i]++;
				}
			}
			p++;
		}
	}

	cout<<p;
	
	return 0;
}
