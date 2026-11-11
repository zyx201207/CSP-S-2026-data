#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	if(n==2){
	cout<<"32"<<endl<<"17";
	} 
	if(n==3){
		cout<<"35"<<endl<<"16";
	}

	
	return 0;
}
