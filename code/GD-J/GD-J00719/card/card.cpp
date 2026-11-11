#include<bits/stdc++.h>
using namespace std;
long long a,b,d,c[500005],cc[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=a;i++){
		int e[500005]={0},d[500005]={0},e1[500005]={0};
		for(int j=i;j<=a;j++){
			if(e[c[j]]){
				d[e1[c[j]]]++;
				d[j]--;
			}
			else{
				e[c[j]]=1;
				e1[c[j]]=j;
			}
		}
		for(int j=i;j<=a;j++){
			d[j]+=d[j-1];
		}
		for(int j=i;j<=a;j++){
			if(!d[j]){
				cc[c[j]]++;
			}
		}
	}
	for(int j=1;j<=b;j++){
			printf("%d ",cc[j]);
		}
	return 0;
} 

