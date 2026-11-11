#include<bits/stdc++.h>
using namespace std;
int c[500005],ans[500005];
int num[500005],sum=1,pj;
int n,m;
bool pd(int a){
	for(int i=1;i<=sum-1;i++){
		if(num[i]==a){
			pj=i;
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)num[j]==0;
		for(int j=i;j<=n;j++){
			if(pd(c[j])){
			    num[sum]=c[j];
			    sum++;
		    }else{
			    num[pj]=c[j];
			    sum=pj+1;
		    }
		}
		for(int j=1;j<=sum-1;j++){
			ans[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
