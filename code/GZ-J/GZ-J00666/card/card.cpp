//姓名：朱栩熠  准考证号：GZ-J00666 学校：贵阳第十八中学 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,xx[100][10000],a;
	stack<int> stk;
	bool instk[1000];
	cin>>n>>m;
	for(int i=0;i<=n;i++) cin>>a[i];
	
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(instk[a[j]]){
				while(stk.top(!=a[j])){
					stk.pop();
					
				}else{
				
				stk.push(a[j]);
				instk[a[j]=1;
			}
			}
			while(!stk.empty()){
				xx[100][stk.top()]=1;
				stk.pop;
			}
			}
			for(int i=0;i<=n;i++){
				for(int j=0;j<=m;i++);
			}
		}
	}
		
	
			
		return 0;
	}
