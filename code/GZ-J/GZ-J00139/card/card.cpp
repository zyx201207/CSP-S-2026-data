//GZ-J00139 遵义市第十一中学 雷朝典
#include<bits/stdc++.h>
using namespace std;
int n,m,b[500001],c[500001],t=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","o",stdout);
	cin>>n>>m;
	for(int y=0;y<n;y++){
		cin>>b[y];
	}
	for(int y=n-1;y>=0;y--){
		if(c[b[y]]==0){
			for(int w=y-1;w>=0;w--){
				if(b[w]==b[y]){
					c[b[y]]=n-w-1;
					t=1;
					break;
				}
			}
			if(t==0){
				c[b[y]]=n-y;
			}
			t=0;
		}
	}
	for(int y=1;y<=m;y++){
		cout<<c[y]<<" ";
	}
} 
