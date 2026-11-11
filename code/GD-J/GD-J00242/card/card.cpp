#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
bool check=1;
void find(int k){
	int card[n+1]={0,a[k]},idx=2;
	for(int i=k+1,flag;i<=n;i++){
		flag=1;
		for(int j=1;j<idx&&flag;j++)if(card[j]==a[i])idx=j+1,flag=0;
		if(flag)card[idx++]=a[i];}
	for(int i=1;i<idx;i++)ans[card[i]]++;}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	if(m<2){
		cout<<n;
		return 0;}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])check=0;}
	if(m<3){
		int ansa=0,ansb=0;
		if(a[n]==1){
			ansa=n;
			for(int i=1;i<=n;i++)ansb+=(a[i]==2);}
		else{
			ansb=n;
			for(int i=1;i<=n;i++)ansa+=(a[i]==1);}
		cout<<ansa<<' '<<ansb;
		return 0;}
	if(check){
		a[0]=a[1];
		for(int i=1;i<=n;i++)if(a[i]!=a[i-1])cout<<i-1<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)find(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;}

