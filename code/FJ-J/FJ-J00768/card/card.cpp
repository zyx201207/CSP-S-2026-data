#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int lst[500005],cnt[300005];
int sai[500005];
void find_m(int x){
	bool flag=0;
	int i=1;
	for(i=1;i<=n;i++){
		if(sai[i]==0) break;
		if(sai[i]==x){
			flag=1;
			continue;
		}
		if(flag) sai[i]=0;
	}
	if(!flag) sai[i]=x;
	return;
}
void play(int i){
	memset(sai,0,sizeof(sai));
	for(int j=i;j<=n;j++){
		find_m(lst[j]);
	}
	for(int j=1;j<=n;j++){
		if(sai[j]!=0) cnt[sai[j]]++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a=n;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	while(1){
		if(a==0) break;
		play(a);
		a--;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" "; 
	return 0;
}
