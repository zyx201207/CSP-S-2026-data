#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
queue<int> q;
bool check(int x){
	int flag=1;
	int s[N];
	for(int i=0;i<q.size();i++){
		if(q.front()==x){
			flag=0;
			break;
		}
		s[i]=q.front();
		q.pop();
	}
	for(int i=0;i<q.size();i++){
		q.push(s[i]);
	}
	if(flag==1){
		return true;
	}
	if(flag==0){
		return false;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(!check(x)){
				for(int c=0;c<q.size();c++){
					q.pop();
				}
				q.push(x);
			}else{
				q.push(x);
			}
		}
		for(int b=0;b<q.size();b++){
			if(q.front()==i){
				ans[i]++;
			}
			q.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
