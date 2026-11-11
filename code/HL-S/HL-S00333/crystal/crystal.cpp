//30
#include<bits/stdc++.h>
using namespace std;
int a[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) f=1;
		else f=0;
	}
	if(f==1){
		int g=1;
		while(m>=0){
			m-=g;
			g++;
		}
		g--;
		cout<<g;
		return 0;
	}
	else{
		int u=a[2]-a[1];
		if(u>m) cout<<1;
		else if(u==m) cout<<2;
		else{
			int y=1;
			while(m>0){
				m-=u;
				u*=2;
				y++;
			}
			cout<<y;
		}
	}
}
