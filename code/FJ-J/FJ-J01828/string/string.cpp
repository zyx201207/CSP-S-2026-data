#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long s;
	char c;//sÊýÁ¿ c×ÖÄ¸ 
}e[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].s>>e[i].c; 
	}
	long long x=1,y=n;
	long long ans=0;
	while(x<y){
		if(e[x].c!=e[y].c){
			if(e[x].s==e[y].s){
				ans+=e[x].s;
				e[x].s=0;
				e[y].s=0;
				x++;
				y--;
			}else if(e[x].s>e[y].s){
				ans+=e[y].s;
				e[x].s-=e[y].s;
				e[y].s=0;
				y--;	
			}else if(e[x].s<e[y].s){
				ans+=e[x].s;
				e[y].s-=e[x].s;
				e[x].s=0;
				x++;
			}
		}else{
			if(e[x].s==e[y].s){
				e[x].s=0;
				e[y].s=0;
				x++;
				y--;
			}else if(e[x].s>e[y].s){
				e[x].s-=e[y].s;
				e[y].s=0;
				y--;
			}else if(e[x].s<e[y].s){
				e[y].s-=e[x].s;
				e[x].s=0;
				x++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

