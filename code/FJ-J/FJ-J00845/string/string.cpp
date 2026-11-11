#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct edge{
	long long a;
	char c;
}e[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>e[i].a>>e[i].c;
	long long nowl=0,nowr=0;
	for(int i=1,j=n;i<=j;){
		if(e[i].c==e[j].c){
			if(e[i].a-nowl==e[j].a-nowr){
				nowl=0,nowr=0;
				i++,j--;
			}else if(e[i].a-nowl>e[j].a-nowr){
				nowl+=e[j].a-nowr;
				nowr=0;
				j--;
			}else{
				nowr+=e[i].a-nowl;
				nowl=0;
				i++;
			}
		}else{
			if(e[i].a-nowl==e[j].a-nowr){
				ans+=e[i].a-nowl;
				nowl=0,nowr=0;
				i++,j--;
			}else if(e[i].a-nowl>e[j].a-nowr){
				ans+=e[j].a-nowr;
				nowl+=e[j].a-nowr;
				nowr=0;
				j--;
			}else{
				ans+=e[i].a-nowl;
				nowr+=e[i].a-nowl;
				nowl=0;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
