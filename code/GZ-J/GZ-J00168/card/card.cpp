//GZ-J00168 遵义市第四中学 陈律金 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	stack<int>k,q;
	cin>>n>>m;
	int ans[m+5]={0};
	for(int i=0;i<n;i++){
		int h;cin>>h;
		q.push(h);
	}
	while(!q.empty()){
		k.push(q.top());
		q.pop();
	}
	for(int i=0;i<n;i++){
		stack<int>f,y;
		if(i!=0)k.pop();
		f=k;
		bool b[m+5]={0};
		while(!f.empty()){
			int v=f.top();
			f.pop();
			if(b[v])while(y.top()!=v)y.pop();
			else{
				y.push(v);
				b[v]=1;
			}
		}
		while(!y.empty()){
			ans[y.top()]++;
			y.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
}

