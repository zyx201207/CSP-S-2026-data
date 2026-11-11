//GZ-J00511 张俊熙 兴义市弘毅中学
#include<bits/stdc++.h>
#include<stack>
#define ll long long
using namespace std;
stack<ll>a;
ll n,m,k[500005],cnt,o[500005];
bool p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&k[i]);
	}for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			
			if(p[k[j]]){
				while(a.top()!=k[j]){
					p[a.top()]=false;
					a.pop();
				}
			}else {
				p[k[j]]=true;
				a.push(k[j]);
			}
			
		}for(int j=1;j<=m;j++){
			if(p[j]) o[j]++; 
		}
		memset(p,false,sizeof(p));
		
	}for(int i=1;i<=m;i++){
		printf("%lld ",o[i]);
	}
	
	return 0;
}
