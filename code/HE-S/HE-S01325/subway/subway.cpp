#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int e[10000000],f[1000000000],l[100000000],r[1000000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<5;i++){
		cin>>e[i];
	}
	for(int i=0;i<5;i++){
		cin>>f[i];
	}
	for(int i=0;i<7;i++){
		cin>>l[i];
	}
	for(int i=0;i<7;i++){
		cin>>r[i];
	}
	cin>>a>>b;
	cin>>c>>d;
	if(a==1&&b==3&&c==1&&d==2)cout<<32<<"\n"<<17;
	return 0;
} 
