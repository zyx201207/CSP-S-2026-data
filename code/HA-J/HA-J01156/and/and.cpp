#include<bits/stdc++.h>
using namespace std;
int n,m;
int mm=-1,d[200005][2]={},top=0;
int ans=0;
int lll(int n){
	while(n>0){
		n/=2;
		ans++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %d",&d[i][0]);
		mm=max(mm,d[i][0]);
 	}
 	mm=lll(mm);
 	int jj=0,ans=0;
 	top=n;
	for(int i=mm;i>=0;i--){
		int q=0,topp=0;
		for(int j=1;j<=top;j++){
			if(((d[j][jj]/int(pow(2,i)))%2)==1){
				d[++topp][!jj]=d[j][jj];
			}
		}
		if(topp>=m){
			jj=!jj;
			top=topp;
			ans+=pow(2,i);
		}
	}
	printf("%d",ans);
}
