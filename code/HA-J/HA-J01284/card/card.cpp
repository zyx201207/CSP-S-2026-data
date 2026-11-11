#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[500005];
bool c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a1,a2,a3,a4;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		c[a[i]]=1;
	}
	if(m==1){cout<<n;return 0;}
	else if(m==2){
		for(int i=1;i<=n;++i){
			if(a[i]==1&&a1!=1) a1=1;
			if(a[i]==2&&a2!=1) a2=1;
			if(a[i]==1&&a1==1){a3=1;a4=0;}
			if(a[i]==2&&a2==1){a3=0;a4=1;}
		}
		cout<<a3<<' '<<a4;
		return 0;
	}
	else{
		for(int i=1;i<=n;++i){
			if(c[a[i]]) cout<<a[i];
		}
		return 0;
	}
	cout<<3<<' '<<1<<' '<<4;
	return 0;
}
