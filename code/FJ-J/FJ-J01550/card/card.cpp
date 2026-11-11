#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s; 
int a[500005];
int num[300005];//每一种值出现的次数 

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//模拟每一局
	bool v[300005];//每一种值是否出现
	
		for(int j=i;j<=n;j++){//打牌 
//		cout<<1;
//		cout<<visit[a[j]];
			if(v[a[j]]==true){//出现过 
				while(s.top()!=a[j]&&s.empty()==false){
					s.pop();
//					cout<<1;
				}
//				visit[a[j]]=0;
//}
			}else{
//				cout<<1;
				s.push(a[j]);
//				cout<<a[j];
				v[a[j]]=true;
			}
		}
		while(s.empty()==false){
			num[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
