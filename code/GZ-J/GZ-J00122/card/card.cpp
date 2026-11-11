// GZ-J00122 贵阳市云岩区中天中学 朱腾予

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[1000],xx[100][1000],ss[100]={0};
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++){
		stack<int> stk;
		bool instk[10000]={0};
		for(int j=i;j<n;j++){
			if(instk[a[j]]){
				while(stk.top()!=a[j]){
					stk.pop();
				}
			}else{
				stk.push(a[j]);
				instk[a[j]] = 1;
			}
		}
		while(!stk.empty()){
			xx[i][stk.top()]=1;
			stk.pop();
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ss[m]+=xx[n][m];
		} 
	}
	for(int i=0;i<m;i++){
		cout << ss[m] << " ";
	}
	return 0;
}
