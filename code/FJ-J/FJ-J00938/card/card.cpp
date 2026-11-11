#include<bits/stdc++.h> 
using namespace std;
const int N=3e5+5;
int a[N],num[N];
int n,m;
bool flag[30005][30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(flag[i][a[j]]){
				while(!s.empty()&&s.top()!=a[j]){
					s.pop();
				}
				if(!s.empty()&&s.top()==a[j]){
					s.pop();
				}
			}
			flag[i][a[j]]=true;
			s.push(a[j]);
		}
		while(!s.empty()){
			num[s.top()]++;
			s.pop(); 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
