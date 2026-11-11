#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int ans[4]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","e",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		ans[0]=1;
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			ans[1]=1;
			if((sr[2]-'A'<=2 && sx[2]-'A'<=2) || (sr[2]-'A'>=3 && sx[2]-'A'>=3)){
				ans[2]=1;
				int x=sr[2]-sx[2];
				if(x<0) x=-x;
				if(x==1){
					ans[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++) cout<<ans[i];
	return 0;
}
