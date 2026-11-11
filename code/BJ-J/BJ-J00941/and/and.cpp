#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m,mx=-1;
queue<int> q;
void f(int id){
	if(q.size()==m){
		int x=q.front();
		q.pop();
	    while(!q.empty()){
			x&=q.front();
			q.pop();
		}
		mx=max(mx,x);
		return;
	}
	else if(id==n+1) return;
	else{
		f(id+1);
		q.push(a[id]);
		f(id+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    f(1);
    cout<<mx;
    return 0;
}
