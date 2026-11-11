#include <bits/stdc++.h>
using namespace std;
int a[514514],b[314514],as[514514],n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int h=0,t=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		stack<int>q;
		for(int j=i;j<=n;j++){
			if (b[a[j]]==1){
				//cout<<a[j]<<"\n";
				
				while(!q.empty()&&q.top()!=a[j]){
					//cout<<1111<<"\n";
					//if (q.front()==a[j])break;
					b[q.top()]=0;
					q.pop();
				}
				if (q.top()==a[j])q.pop();
				b[a[j]]=0;
			}q.push(a[j]);
			b[a[j]]=1;
		}while(!q.empty()){
			//cout<<q.front()<<" ";
			as[q.top()]++;
			q.pop();
		}//cout<<"\n";
	}for (int i=1;i<=m;i++){
		cout<<as[i]<<" ";
	}
	return 0;
}
