#include<bits/stdc++.h>
using namespace std;
int n,m,cd=0,s=0;
int a[200005];
int st[100005];
int wz[200005];
int c[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=n,j=1;i>j;i--,j++){
		swap(a[j],a[i]);
	}
	for(int i=1;i<=n;i++){
		if(wz[a[i]]==0){
			cd++;
			wz[a[i]]=cd;
			c[cd]=a[i];
		}
		else{
			cd=wz[a[i]];
		}
		for(int j=1;j<=cd;j++){
			st[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<st[i]<<" ";
	}
	return 0;
}
