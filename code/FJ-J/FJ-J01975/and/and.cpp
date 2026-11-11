#include<bits/stdc++.h>
using namespace std;
int n[100000];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int a,m,b,c=0,w;
	cin>>a>>m;
	w=m;
	for(int i=1;i<=a;i++){
		cin>>b;
		n[i]=b;
	}
	for(int i=1;i<=a;i++){
		for(int j=i+1;j<=a;j++){
			m=w;
			while(m--){
				n[i]=n[i]&n[j];
			}
			if(n[i]>c){
				c=n[i];
			}
		}
	}
	cout<<c;
	return 0;
}
