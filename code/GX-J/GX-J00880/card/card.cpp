#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500010];
int ans[300010];
bool f[300010];
stack<int>t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//bao li
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		memset(f,0,sizeof(f));
		for(int i=j;i<=n;i++){
		
			if(f[a[i]]==0){
				f[a[i]]=1;
				t.push(a[i]);
				//cout<<1<<endl;
			}
			else{
				while(!t.empty()){
					int x=t.top();
					if(x==a[i]){
						t.pop();
						break;
					}
					f[x]=0;
					t.pop();
				}
				t.push(a[i]);
				//cout<<2<<endl;
			}
			
		}
		while(!t.empty()){
			int x=t.top();
			ans[x]++;
			t.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
