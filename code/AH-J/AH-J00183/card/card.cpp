#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s;
bool vis[300010];
int a[500010];
int f(int k,int x){
	for(int i=x;i<=n;i++){
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			s.push(a[i]);
		}else{
			while(!s.empty()){
				if(s.top()==a[i]){
					break;
				}else{
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
	}
	while(!s.empty()){
		//int l=s.top();
		//cout<<l<<" ";
		if(s.top()==k){
			while(!s.empty()){
				s.pop();
			}
			return 1;
		}
		s.pop();
	}
	//cout<<endl;
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			memset(vis,0,sizeof(vis));
			//cout<<"#"<<i<<" "<<j<<endl;
			ans+=f(i,j);
		}
		cout<<ans<<" ";
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

