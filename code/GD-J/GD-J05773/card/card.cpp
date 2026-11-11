#include<bits/stdc++.h>
using namespace std;
int a[500001],b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(l<=n){
		string s;
		int sum=0;
		for(int i=l;i<=n;i++){
			int y=s.find(a[i]);
			if(y!=-1){
				s.erase(y,s.size()-y+1);
			}
			s+=(a[i]);
		}
		for(int i=1;i<=m;i++){
			if(s.find(i)!=-1) b[i]++;
		}
		l++;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
