#include<bits/stdc++.h>
using namespace std;
string n[1005];
int main(){
	freopen('travel.in'.r.stdin);
	freopen('travel.out'.w.stdout);
int a;
cin>>a;
int b=1;
	for(int i=0;i<=a;i++){
		int m;
		cin>>m;
		for(int j=0;j<=m;j++){
			cin>>n[b];
			b++;
		}
	}
	b=b/2;
	int c=0;
	if(b%2==0){
		int w=b+1;
	
	
	for(int i=b;;i--){
		if(i==0){
				break;
			}
		if(n[i]!=n[w]){
			c++;
		}
		w++;
			
		}
}
	else{
		int w;
		for(int i=b+1;;i++){
			if(w==0){
				break;
			}
		if(n[i]!=n[w]){
			c++;
		}
		w--;

	}
}


	
	cout<<c;
	

	return 0;
}
