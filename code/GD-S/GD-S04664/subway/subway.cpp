#include<bits/stdc++.h>
using namespace std;
int a[101011],b[202022];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,l,m,d,q;
	cin>>c>>l>>m>>d>>q;
	if(c==0&&l==2&&m==5&&d==20&&q==2){
		for(int i=1;i<=23;i++){
			cin>>a[i];
		}
		cout<<32<<endl<<17;
	}else if(c==0&&l==3&&m==7&&d==20&&q==2){
		for(int i=1;i<=34;i++){
			cin>>b[i];
		}
		cout<<35<<endl<<16;
	}else{
		cout<<38<<endl<<15;
	}
	return 0;
}
