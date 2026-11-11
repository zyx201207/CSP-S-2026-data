#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],dc[N],m;
struct node{
	int ct;
};
node b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int begin=1,now;
	bool ok;
	while(begin){
		if(begin==n+1) break;
		for(int i=1;i<=n;i++) dc[i]=0;
		dc[begin]=a[begin];
		for(int i=begin+1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]!=dc[j]) ok=1;
				else{
					ok=0;
					now=j;
					break;
				}
			}
			if(ok) dc[i]=a[i];
			else{
				
				for(int c=now;c<=n;c++) dc[c]=0;
				dc[i]=a[i];
			}
		}
		for(int z=1;z<=n;z++){
			if(dc[z]!=0) b[dc[z]].ct++;
		}
		begin+=1;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i].ct<<" ";
	}
	return 0;
}
