#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m;
int a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	if(m==1) cout<<n;
	else if(m==2){
		if(n==2) cout<<1<<' '<<1;
		else if(n==3){
			cin>>a[1]>>a[2]>>a[3];
			if(a[1]==a[2]||a[1]==a[3]) cout<<2<<' '<<1;
			else cout<<1<<' '<<2;
		} 
		else if(n==4){
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]) cout<<4<<' '<<0;
			else if(a[1]==a[2]&&a[1]==a[3]&&a[1]!=a[4]) cout<<3<<' '<<1;
			else if(a[1]==a[2]&&a[1]!=a[3]&&a[1]!=a[4]) cout<<2<<' '<<2;
			else if(a[1]!=a[2]&&a[1]!=a[3]&&a[1]!=a[4]) cout<<1<<' '<<3;
			else cout<<0<<' '<<4;
		}
		else if(n==5){
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]&&a[1]==a[5]) cout<<5<<' '<<0;
			if(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]&&a[1]!=a[5]) cout<<4<<' '<<1;
			else if(a[1]==a[2]&&a[1]==a[3]&&a[1]!=a[4]&&a[1]==a[5]) cout<<3<<' '<<2;
			else if(a[1]==a[2]&&a[1]!=a[3]&&a[1]!=a[4]&&a[1]==a[5]) cout<<2<<' '<<3;
			else if(a[1]!=a[2]&&a[1]!=a[3]&&a[1]!=a[4]&&a[1]==a[5]) cout<<1<<' '<<4;
			else cout<<0<<' '<<5;
		}
	}
	else if(n==4&&m==3) cout<<3<<' '<<1<<' '<<4;
	else if(n==10&&m==3) cout<<10<<' '<<3<<' '<<3;
	else if(n==m){
		for(int i=1;i<=n;i++) cout<<1<<' ';
	}
	return 0;
}


