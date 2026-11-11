#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,i=1,a,d,x[100000001];
	cin>>c>>t;
	if(i<=t){
		int f;
		cin>>a>>d;
		for(int j=1;j<=a;j++){
			cin>>x[j];
			if(j>=2&&x[j]-x[j-1]==x[j-1]-x[j-2])f=1;
			else if(x[j]-x[j-1]!=x[j-1]-x[j-2])f=0;
			else break;
		}
		if(f==1&&d/(x[a]-x[a-1])<=a/2+1)cout<<"1"<<endl;
		else  cout<<"0"<<endl;
		i++;
	}
	return 0;
}
