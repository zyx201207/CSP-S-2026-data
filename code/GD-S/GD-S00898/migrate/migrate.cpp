#include<bits/stdc++.h>
using namespace std;
struct V{
	int a,b;
}c;
int cc,t,n,d;
int a[2000005],as,vis[2000005];
int gs(int aa,int b){
	queue<V>q;
	q.push({aa,0});
	while(!q.empty()){
		c=q.front();
		//cout<<c.a<<" ";
		if(a[q.front().a]==b){
			q.pop();
			//cout<<"//";
			if(a[(int)q.front().a]!=b)return 0;
			//cout<<"*";
			q.pop();
			if(a[(int)q.front().a]==b&&q.front().b==c.b)return 0;
			return 1;
		}
		for(int i=n;i>c.a;i--){
			if(vis[i]==0&&(a[i]-a[(int)c.a])<=d){
				q.push({a[i],c.b+1});
				vis[i]=1;
				if(a[i]==b)vis[i]=0;
			}
		}
		q.pop();
	}
}

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		as=0;
		for(int j=1;j<n;j++){
			for(int z=j+1;z<=n;z++){
				for(int id=1;id<=n;id++)vis[id]=0;
				vis[j]=1;
				if(gs(j,a[z])==1)as++;
			}
		}
		cout<<as<<endl;
	}
}
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
