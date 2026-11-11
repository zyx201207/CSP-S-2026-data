#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0,m=0,an[1000001]={0},ans=0,aa=0;
	int last[10000001]={0};
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)scanf("%d",an[i]);
	for(int i=1;i<=n;i++){
		int b[1000001]={0};
		for(int j=i;j<=n;j++){
			if(b[an[j]]!=0){
				for(int k=1;k<=m;k++){
					b[k]=0;
				}
			}
			b[an[j]]++;
		}
		for(int j=1;j<=m;j++)if(b[j]!=0)last[j]++;
	}
	for(int i=1;i<=m;i++)cout<<last[i];
	return 0;
}
