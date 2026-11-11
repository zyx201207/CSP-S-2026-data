#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
long long n,m,a[N],ans[N],ap[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}stack<int>card;
	for(int i=1;i<=n;i++){
		memset(ap,0,sizeof(ap));
		for(int j=i;j<=n;j++){
			if(ap[a[j]]!=0){
				for(;card.size()>=ap[a[j]]&&card.size()!=0;){
					ap[card.top()]=0;
					if(card.top()==a[j]){
						card.pop();break;
					}
					card.pop();
				}
			}
			card.push(a[j]);
			ap[card.top()]=card.size();
		}
		while(card.size()!=0){
			ans[card.top()]++;
			card.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
