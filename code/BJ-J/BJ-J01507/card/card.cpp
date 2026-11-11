/*
card

预处理，直接跳到last[now]

留下就加

40-52

*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],last[500005],ans[300005],b[300005]={};
bool flag=true;
void goo(int st){
	for(int i=1;i<=m;i++){
		b[i]=0;
	}
	while(st<=n){
		b[a[st]]=1;
		if(last[st]){
			st=last[st]+1;
		}else{
			st++;
		}
	}
	for(int i=1;i<=m;i++){
		ans[i]+=b[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=false;
		}
	}
	if(flag){//A
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		flag=true;
		for(int j=n;j>i && flag;j--){
			if(a[j]==a[i]){
				last[i]=j;
				flag=false;
			}
		}
	}
	for(int i=1;i<=n;i++){
		goo(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
