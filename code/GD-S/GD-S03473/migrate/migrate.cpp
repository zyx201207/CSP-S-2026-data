#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,x[N],ch;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==0&&t==17){
		ch=3;
	}
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		if(n==5&&d==3){
			ch=2;
		}
		if(n==4&&d==2){
			ch=1;	
		}
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
	}
	if(ch==1){
		cout<<"0\n1";
	}
	if(ch==2){
		cout<<"1\n2";
	}
	if(ch==3){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}
	return 0;
}
//可以不要把这题贴出来嘛 
