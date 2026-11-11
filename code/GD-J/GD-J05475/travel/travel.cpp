#include<bits/stdc++.h>
using namespace std;
int a,b,s,n,m,c,d;
string x,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>x>>b>>y;
	for(int i=1;i<=x.size();i++)
	{s=x[0]*10+x[1];
	n=x[2];
	}
	for(int i=1;i<=y.size();i++)
	{m=y[0]*10+y[1];
	c=y[2];
	}
	if(a==b){cout<<1;d++;
	}
	else cout<<0;
	if(m==s&&d==1){cout<<1;d++;
	}
	else cout<<0;
	if(n+c!=135&&d==2){cout<<1;d++;
	}
	
	else cout<<0;
	
	if(n-c==1 && d==3||c-n==1&&d==3)cout<<1;
	else cout<<0;
	return 0;
}
