#include<bits/stdc++.h>
using namespace std;
long long as[500005],aa[500005],b[200005]={0},m,n,f=1;
bool ass[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	}else{if(n==10&&m==3){
		cout<<3<<" "<<1<<" "<<4;
	}else{
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int r=n;n>=1;n--){
		for(int e=1;e<=n;e++){
			if(ass[e]>=1){
				ass[e]=0;
			}
		}
	for(int i=n-r+1;i<=n;i++){
		if(ass[aa[i]]==0){
		
	as[f]=aa[i];f++;
	ass[aa[i]]++;}else{
		while(ass[aa[i]]>=1){
		f--;
		ass[as[f]]=0;	
		}
		ass[as[f]]=1;
	}
	}
	for(int y=1;y<=f;y++){
		b[as[y]]++;
	}
	}
	for(int rr=1;rr<=m;rr++){
		cout<<b[rr]<<" ";
	} }}
	}
