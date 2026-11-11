#include<bits/stdc++.h>
using namespace std;
bool book[200005][90000000009];
int shu[200005],ml=-1;
int js(bool num[]){
	int ans;
	for(int i=0;i<=ml;i++){
		if(num[i]==1)ans+=2^i;
	} 
	return ans;
}
void ze(int a,int b){
	int i=0;
    for(;i<=i;i++){
    	if(2^i>=a){
    		i=i-1;
    		break;
		}
	}
	if(i>ml)ml=i;
	for(int j=i;j>=0;j--){
		if(a>=2^j){
			a-=2^j;
			book[b][j]=1;
		}else{
			book[b][j]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shu[i];
		ze(shu[i],i);
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			if(shu[i]>maxx)maxx=shu[i];
		}
		cout<<maxx;
	}else if(m==2){
		int maxx=-1;bool num[ml+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=0;k<=ml;k++){
					if(book[i][k]+book[j][k]==2){
						num[k]=1;
					}else num[k]=0;
				}
				if(js(num)>maxx)maxx=js(num);
			}
		}
	}
	return 0;
}
