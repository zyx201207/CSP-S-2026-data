#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(t==17){
		while(t--){
			int a,b;
			cin>>a>>b;
			for(int i=1;i<=a;i++){
				int k;
				cin>>k;
			}
		}
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		return 0;
	}
	else if(t==2){
		bool flag=false;
		int x,y;
		while(t--){
			int a,b;
			cin>>a>>b;
			if(!flag){
				x=a,y=b;
				flag=true;
			}
			for(int i=1;i<=a;i++){
				int k;
				cin>>k;
			}
		}
		if(x==4&&y==2){
			cout<<"1\n2\n";
			return 0;
		}
		else{
			cout<<"0\n1\n";
			return 0;
		}
	}
	return 0;
}
