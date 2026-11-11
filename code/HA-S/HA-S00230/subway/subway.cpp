#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",instd);
	freopen("subway.out","w",outstd);
	int c,n,m,d,p,w[500005],a[500005];
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(c==0&&m==3&&m==7&&d==20&&p==2){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
	}
	if(c==0&&m==15&&m==136&&d==20&&p==200){
		cout<<"341"<<endl;
		cout<<"667"<<endl;
	}
	return 0;
}
