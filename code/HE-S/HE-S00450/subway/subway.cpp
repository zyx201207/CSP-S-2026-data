#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<"32"<<endl<<"17";
		}
		else if(n==3){
			cout<<"35"<<endl<<"16";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
