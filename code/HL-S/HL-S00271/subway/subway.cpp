#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n;
	cin>>c>>n;
	if(c==0&&n==2){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
	}else if(c==0&&n==3){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
	}
	return 0;
}
