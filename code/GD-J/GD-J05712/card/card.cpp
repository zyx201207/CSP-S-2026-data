#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100005];
	int hve[100005]={0};
	stack<int> x;
	scanf("%d%d",&n,&m);
	int sum[100005]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(hve,0,sizeof(hve));
		for(int j=i;j<=n;j++){
			if(hve[a[j]]==0){
				hve[a[j]]++;
				x.push(a[j]);
			}
			else{
				while(1){
					if(x.top()==a[j])	break;
					hve[x.top()]--;
					x.pop();
				}
			}
		}
		while(!x.empty()){
			if(x.top()>=1 && x.top()<=m){
				sum[x.top()]++;
			}
			x.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
