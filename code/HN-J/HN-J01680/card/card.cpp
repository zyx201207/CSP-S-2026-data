#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],ans[300005];
	bool used[300005]={0};
	stack<int>s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!used[a[j]]){
				s.push(a[j]);
				used[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					used[s.top()]=0;
					s.pop();
				}
				used[s.top()]=0;
				s.pop();
			}
		while(!s.empty()){
			if(s.top()<=m){
				ans[s.top()]++;	
			}
			s.pop();
		}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
