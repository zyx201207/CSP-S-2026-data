#include<bits\stdc++.h>
using namespace std;
int n,m;
stack <int> s;
long long a[500010],res[500010];
bool b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s.push(int(a[j]));
				b[a[j]]=1;
			}else while(s.top()!=int(a[j]))s.pop();
		}
		while(s.empty()==0){
			res[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
/*
10 3 3 1 2 1 3 2 3 1 2 1
*/
