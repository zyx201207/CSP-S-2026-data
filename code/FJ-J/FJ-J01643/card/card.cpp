#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],s[300005];
void turn(int w){
	if(w>n)return;
	b[w]=a[w];
	turn(w+1);
	return;
}
void card(int q,int p,int w){
	if(w>n){
		for(int i=q;i<p;i++)s[b[i]]++;
		return;
	}
	int k=0;
	for(int i=q;i<p;i++){
		if(b[i]==b[p]){
			k=p-i;
			break;
		}
	}
	cout<<endl;
	p-=k;
	b[p+1]=a[w+1];
	p++;
	card(q,p,w+1);
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		turn(i);
		int z=i;
		card(i,z,i);
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
