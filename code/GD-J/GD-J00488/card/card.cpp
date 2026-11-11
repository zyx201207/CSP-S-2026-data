#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
vector<int>l;
vector<int>c;
vector<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	a.resize(n+1,0);
	c.resize(m+1,0);
	if(n>5||m>2){
		l.resize(n+1,0);
		s.resize(m+1,0);	
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[a[i]]++;
			if(a[i]!=a[i-1]){
				l[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			s[i]=s[i-1]+c[i];
		}
		for(int i=1;i<=m;i++){
			if(s[i]==s[i-1]){
				printf("0 ");
			}
			else{
				printf("%d ",s[i]);
			}
		}
		return 0;
	}
	return 0;
}
