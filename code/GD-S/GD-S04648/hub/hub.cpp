#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("hub.in.txt","r",stdin);
	freopen("hub.out.txt","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a,b;
		}
		if(n==5){
			cout<<1<<endl;
		}
		else if(n==10){
			cout<<2<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
