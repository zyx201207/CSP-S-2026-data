#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,a,ans=0,b[1000000],c[1000000];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a;
		if(b[a]<1)q.push(a),b[a]++,sum++;
		else{
			while(!q.empty()){
				if(q.front()==a){
					break;
				}
				sum-=q.front();
				b[q.front()]--;
				q.pop();
			}
		}
		c[sum]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
		return 0;
} 
