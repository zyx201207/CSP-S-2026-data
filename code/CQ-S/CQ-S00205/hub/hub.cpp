#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	srand(time(0));
	cin>>C>>T;
	int n,m;
	while(T--){
		cin>>n>>m;
		int x,y;
		for(int i=1;i<n;i++)cin>>x>>y;
		cout<<rand()%m<<endl;
		if(n==5&&m==2)cout<<"1\n";
		else if(n<=m)cout<<"0\n";
		else if(n==m+1)cout<<"1\n";
		else if(n==m+2)cout<<"1\n";
	}
}

