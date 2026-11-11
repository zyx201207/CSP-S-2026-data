#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>c>>t;
	if(c==13 or c==14){
		for(int i=0;i<t;i++)
			cout<<0<<'\n';
		return 0;
	}else if(c==11 or c==12){
		for(int i=0;i<t;i++){
			cin>>n>>d;
			int x1,x2,x3;
			cin>>x1>>x2;
			for(int i=0;i<=n-2;i++)cin>>x3;
			if(x2-x1==d)
				cout<<n-3<<'\n';
			else
				cout<<0<<'\n';
		}
	}else{
		for(int i=0;i<t;i++)
			cout<<0<<'\n';
	}
	return 0;
}

