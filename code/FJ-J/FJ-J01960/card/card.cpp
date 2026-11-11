#include <bits/stdc++.h>
using namespace std;
long long n,m,lb[500001],hg[300001],jg[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lb[i];
		hg[lb[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			jg[lb[i]]=n;
		}else if(i==1){
			jg[lb[i]]++;
		}else{
			for(int j=i-1;j>0;j--){
				if(j!=hg[lb[j]]&&hg[lb[j]]>i){
					jg[lb[i]]+=i-j;
					break;
				}else if(j==1){
					jg[lb[i]]+=i-j;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jg[i]<<" ";
	}
	return 0;
}
