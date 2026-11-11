#include<bits/stdc++.h>
using namespace std;
struct node{
	char a;
	int num;
}just[200001];
int n;
int lp;
int rp;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>just[i].num>>just[i].a;
	}
	lp=1;
	rp=n;
	while(lp<rp){
		if(just[lp].num<just[rp].num){
			if(just[lp].a!=just[rp].a){
				ans+=just[lp].num;	
			}
			just[rp].num-=just[lp].num;
			just[lp].num=0;
			lp++;
		}
		if(just[lp].num==just[rp].num){
			if(just[lp].a!=just[rp].a){
				ans+=just[lp].num;	
			}
			just[rp].num-=just[rp].num;
			just[lp].num=0;
			lp++;
			rp--;
		}
		if(just[lp].num>just[rp].num){
			if(just[lp].a!=just[rp].a){
				ans+=just[rp].num;	
			}
			just[lp].num-=just[rp].num;
			just[rp].num=0;
			rp--;
		}
	}
	cout<<ans;
	return 0;
}
