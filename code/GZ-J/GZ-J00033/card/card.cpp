// GZ-J00033 ºÎçâå· 
#include<bits/stdc++.h>
using namespace std;
int pai[100005];
int t[300005];
int zz[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
	for(int i=1;i<=n;i++){
		int r=0;
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int i0=0;i0<=r;i0++){
				if(zz[i0]==pai[j]){
					flag=1;
				}
				if(flag==1){
					r--;
				} 
			}
			zz[r]=pai[j];
			r++;
		}
		for(int j=0;j<r;j++){
			t[zz[j]]++;
			zz[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
