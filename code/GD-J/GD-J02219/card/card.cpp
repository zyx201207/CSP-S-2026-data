#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],sum[M],num[M],whe[N];
int n,m;
bool A,B,f[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[a[i]]++;
		if(i!=1&&a[i-1]>a[i])A=true;
		if(i!=1&&a[i]==a[i-1])B=true;
	}
	if(A==false){
		int cnt=0;
		for(int i=1;i<=m;i++){
			cnt+=sum[i];
			printf("%d ",cnt);
		}
		return 0;
	}

		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			   if(f[a[j]]==false){
			   	f[a[j]]=true;
			   	num[a[j]]++;
			   }
			   else{
			   		for(int k=j-1;k>=i+1;k--){
			   			if(a[k]==a[j])break; 
						   if(f[a[k]]==true)num[a[k]]--;	
						   f[a[k]]=false;
						  
					}
			   }
			}memset(f,false,sizeof(f));
		}
		for(int i=1;i<=m;i++)printf("%d ",num[i]);
	
	return 0;
}
