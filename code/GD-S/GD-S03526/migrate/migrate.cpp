#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int pd=0,o=0;
		for(int i=1;i<=n;i++){
			int x=a[i]-a[1];
			int y=a[n]-a[i];
			if(x<=d&&y<=d)pd=1,o++;
		}
		if(pd){
			if(o==2){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
			continue;
		}
//		int bl=1;
//		for(int i=1;i<n;i++){
//			if(a[i+1]-a[i]!=a[2]-a[1]){
//				bl=0;
//				break;
//			} 
//		} 
//		if(bl){
		int cha=a[n]-a[1];
		cout<<cha%d<<'\n';
//			continue;
//		}
	}
	return 0;
} 
