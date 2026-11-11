#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],res[300010],flag[300010];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==2){
		for(int i=1;i<=n;i++){
			res[a[i]]++;
			if(a[i]!=a[n])res[a[n]]++;
		}
		for(int i=1;i<=2;i++)cout<<res[i]<<" ";
	}else{
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				if(flag[a[i]]){
					while(!s.empty()&&s.top()!=a[i]){
						flag[s.top()]=0;
						s.pop();
					}
				}else{
					flag[a[i]]=1;
					s.push(a[i]);
				}
			}
			while(!s.empty()){
				int t=s.top();
				res[t]++;
				flag[t]=0;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",res[i]);
		}		
	}
	return 0;
}
