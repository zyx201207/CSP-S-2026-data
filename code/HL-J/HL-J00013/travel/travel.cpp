#include <bits/stdc++.h>
using namespace std;
struct che{
	string t;
	string z;
}a[3];
int b[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++) cin>>a[i].t>>a[i].z;
	if(a[1].t==a[2].t){
		b[1]=1;
		if(a[1].z[0]==a[2].z[0] && a[1].z[1]==a[2].z[1]){
			b[2]=1;
			if((a[1].z[2]=='A' || a[1].z[2]=='B' || a[1].z[2]=='C') && (a[2].z[2]=='A' || a[2].z[2]=='B' || a[2].z[2]=='C') || (a[1].z[2]=='D' || a[1].z[2]=='F') && (a[2].z[2]=='D' || a[2].z[2]=='F')){
				b[3]=1;
				if(int(a[1].z[2])+1==int(a[2].z[2]) ||int(a[1].z[2])+1==int(a[2].z[2])){
					b[4]=1;
				}
			}
			
		}
	}
	for(int i=1;i<=4;i++){
		cout<<b[i];
	} 
	return 0;
}
