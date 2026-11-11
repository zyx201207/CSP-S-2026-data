#include<bits/stdc++.h>
using namespace std;
int n,m,p[640032],a[320016];
bool yn[320016];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;i<=m;i++){
			yn[j]=false; 
		}
		for(int j=i;j<=n;j++){
			if(yn[p[j]]==true){
				while(1){
					if(q.front()==p[j]) break;
					yn[q.front()]=false;
					q.pop();
				}
			}
			else{
				q.push(p[j]);
				yn[p[j]]=true;
			}
		}
		while(!q.empty()){
//			cout<<q.front()<<" ";
			a[q.front()]++;
			q.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
