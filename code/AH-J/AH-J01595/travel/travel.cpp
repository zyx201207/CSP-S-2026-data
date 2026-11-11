#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,ans1,ans2,p,q;
	char a,b,c,d,e,f;
	cin>>n;
	cin>>a>>b>>c;
	cin>>m;
	cin>>d>>e>>f;
	ans1=(a-'0')*10+(b-'0'),ans2=(d-'0')*10+(e-'0');
	p=c-'A',q=f-'A';
	if(n==m)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(ans1==ans2)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(p<=2&&q<=2){
		cout<<1;
		if(abs(p-q)==1)
			cout<<1;
		else
			cout<<0;
	}
	else
		if(p>=3&&q>=3){
			cout<<1;
			if(abs(p-q)==2)
				cout<<1;
			else
				cout<<0;
		}
		else
			cout<<"00";
	return 0;
}
