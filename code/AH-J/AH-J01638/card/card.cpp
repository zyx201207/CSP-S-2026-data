#include<bits/stdc++.h>
using namespace std;
int a,last[100010],mark[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,head;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		last[i]=i;
	}
	head=m;
	while(n--){
		cin>>a;
		if(last[a]==0){
			head++;
			last[a]=head;
		}else{
			for(int i=last[a]+1;i<=head;i++){
				last[i]=0;
			}
			head=last[a];
		}
		for(int i=1;i<=head;i++){
			if(last[i]!=0)mark[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mark[i]<<" ";
	}
	return 0;
}
