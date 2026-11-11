#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[500001],ans[300001];
short b[300001];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	/*提交时去掉freopen！！！*/
	freopen("card.out","w",stdout);
	
	memset(ans,0,sizeof(ans));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		while(!s.empty())s.pop();
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while((s.top())!=a[j]){
					b[s.top()]=0;
					s.pop();
    			}
    			s.pop();
			}
			b[a[j]]=1;
			s.push(a[j]);
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
 	printf("\n");
 	return 0;
}
