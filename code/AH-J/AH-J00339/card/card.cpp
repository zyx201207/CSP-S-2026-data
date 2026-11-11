#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int> s;
int n,a[500005],cnt,sz[500005],m,b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=1;
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					s.pop();
					b[s.top()]=0;
				}
			}
		}
		while(!s.empty()){
			sz[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sz[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//你好
