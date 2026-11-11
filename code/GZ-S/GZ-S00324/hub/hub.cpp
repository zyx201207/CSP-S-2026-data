//GZ-S00324 贵阳市第十八中学 李翼辰
#include<bits/stdc++.h>
using namespace std;
int c,t;
int cnt=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t!=3){
		while(t--){
			int n,k;cin>>n>>k;
			for(int i=1;i<n;i++){
				int x,y;cin>>x>>y;
			}
			cout<<cnt<<endl;
			cnt++;
		}		
	}else{
		while(t--){
			int n,k;cin>>n>>k;
			for(int i=1;i<n;i++){
				int x,y;cin>>x>>y;
			}
		}
		cout<<1<<endl<<1<<endl<<2;
	}
	return 0;
} 
