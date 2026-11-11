//GZ-J00310 遵义市第四中学 张君皓 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen(" travel.out","w",stdout);
	int x,y,n,i,m;
	char a[10],b[10];
	cin>>x;
	for(i=1;i<=3;i++){
		cin>>a[i];
	}
	cin>>y;
	for(i=1;i<=3;i++){
		cin>>b[i];
	}
	n=(a[1]-'0')*10+(a[2]-'0');
	m=(b[1]-'0')*10+(b[2]-'0');
	if(x==y){
		cout<<"1";
		if(n==m){
			cout<<"1";
			if(a[3]<'D'&&b[3]<'D'||a[3]>'C'&&b[3]>'C'){
				cout<<"1";
				if(((a[3]-'0')==(b[3]-'0'-1))||((a[3]-'0'-1)==(b[3]-'0'))){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
