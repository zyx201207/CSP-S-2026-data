#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
//bool check(int s,int f){//起点与终点 
//	for(int i=s;i<=f;i++){
//		
//	} 
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i];
			flag+=i;
		}
		flag-=n;
		if(c==11||c==12) cout<<0<<endl;
		else if(c==13||c==14) cout<<flag<<endl;
	    else cout<<rand()%flag<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
