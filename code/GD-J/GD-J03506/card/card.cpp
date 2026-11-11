#include<bits/stdc++.h>
using namespace std;
int n,m;
int q[500010],qx[500010],mx[300010],qw[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		if(qw[q[i]]>0){
			qx[qw[q[i]]]=i;
		}
		qw[q[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int k=i;
		while(k<=n){
			while(qx[k]!=0){
				k=qx[k];
			}
			mx[q[k]]+=1;
			k++;
		}
	}for(int i=1;i<=m;i++){
		cout<<mx[i]<<" ";
	}
	return 0;
}
