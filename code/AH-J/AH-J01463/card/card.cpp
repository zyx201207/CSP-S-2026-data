#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
map<int,int>tong;
queue<int>qu;
map<int,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		while(!qu.empty()){
			qu.pop();
		}mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==1){
				queue<int>temp;
				bool c=0;
				while(!qu.empty()){
					if(qu.front()==a[j]){
						c=1;
					}else if(c!=1){
						temp.push(qu.front());
					}
					qu.pop();
				}while(!temp.empty()){
					qu.push(temp.front());
					temp.pop();
				}
			}qu.push(a[j]);
			mp[a[j]]=1;
		}while(!qu.empty()){
			tong[qu.front()]++;
			qu.pop();
		}
	}for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
