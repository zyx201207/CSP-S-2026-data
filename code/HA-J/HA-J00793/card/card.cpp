#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],ton[300005];
int st[300005];
int tot=0;
void pop(){
	st[tot]=0;
	tot--;
}
void push(int x){
	st[tot+1]=x;
	tot++;
}
bool empty(){
	return tot==0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ton[j]=0;
			st[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(ton[a[j]]==1){
				while(st[tot]!=a[j]){
					ton[st[tot]]=0;
					pop();
				}
			}
			else{
				push(a[j]);
				ton[a[j]]=1;
			}
		}
		while(!empty()){
			ans[st[tot]]++;
			pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
