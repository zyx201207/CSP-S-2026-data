#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[500005];
stack<int> s;
bool num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(num[a[i]]!=0){
				while(s.top()!=a[i]){
					num[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[i]);
				num[a[i]]=1;
			}
		}
		while(!s.empty()){
			sum[s.top()]++;
			s.pop();
		}
		for(int i=1;i<=m;i++){
			num[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
	return 0;
}

