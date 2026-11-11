#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int p,c;
	cin>>c;
	cin>>p;
	for(int i=1;i<=p;i++){
		cout<<(i+c-1)%2<<endl;
	}
	return 0;
} 

