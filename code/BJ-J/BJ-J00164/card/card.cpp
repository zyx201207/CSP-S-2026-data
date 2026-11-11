#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],ans[10005],v;
stack<int> s;
int vis[10005],f;
queue<int> z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){    
		cin>>a[i];
		s.push(a[i]);
		z.push(a[i]);
		if(vis[a[i]]>0){
			while(s.top()!=a[i]&&!s.empty()){
				vis[s.top()]--;
				v=s.top();
				s.pop();
			}
		}else {
			if(v!=-1){
				z.pop();
			}	
			z.push(a[i]);
			vis[a[i]]++;
			v=-1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				//cout<<i<<':'<<j<<':'<<vis[j]<<" ";
				ans[j]+=1;
			}
		}
		
		vis[a[i]]++;
	}
	for(int i=2;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[1];
    return 0;
}
