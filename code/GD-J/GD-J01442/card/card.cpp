#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		while(!q.empty())q.pop();
		for(int k=i;k<=n;k++){
			long long p=0;
			for(int j=1;j<=q.size();j++){
				int fr=q.front();
				q.pop(),q.push(fr);
				if(fr==a[k])p=j;
			}
			if(p!=0){
				for(int j=1;j<=p;j++)
					q.pop();
			}
			q.push(a[k]);
			for(int j=1;j<=q.size()-1;j++){
				long long fr=q.front();
				q.pop(),q.push(fr);	
			}
		}
		while(!q.empty())a[q.front()]++,q.pop();
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",a[i]);
	return 0;
}
