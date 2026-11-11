#include<bits/stdc++.h>
using namespace std;

int n,m;
int c[500005],now[300005],a[500005];
stack<int>p;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>0;i--){
		if(now[c[i]]==0){
			p.push(c[i]);
			now[c[i]]=1;
		}else{
			while(p.top()!=c[i]){
				now[p.top()]=0;
				p.pop();
			}
		}
		for(int s=1;s<=m;s++){
			a[s]+=now[s];
		}
	}
	for(int s=1;s<=m;s++){
		cout<<a[s]<<' ';
	}
	return 0;
}

