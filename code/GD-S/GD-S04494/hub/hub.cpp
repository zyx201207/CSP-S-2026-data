#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,b;
	cin>>c>>b;
	for(int i=1;i<=b;i++){
		cout<<pow(c-i,i+2)-i*i*i<<endl;
	}
	return 0;
}
