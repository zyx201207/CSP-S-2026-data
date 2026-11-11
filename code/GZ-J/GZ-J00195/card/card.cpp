//GZ-J00195 贵阳市南明区李端棻中学 周熙沅 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int b[n+5];
	int d[m+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool c=false;
		for(int j=0;j<i;j++){
			if(b[j]==a[i]){
				c=true;
			}
		}
		if(c){
			for(int j=0;j<i;j++){
				b[i]=0;
			}
		}else{
			b[i]=a[i];
		}
		d[a[i]]++;
	}
	for(int i=0;i<n;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
