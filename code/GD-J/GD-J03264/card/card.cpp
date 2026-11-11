#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int pn[5*MAXN],nums[3*MAXN],t[MAXN*5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>pn[i];
	}
	stack<int>st;
	for(int step=1;step<=n;step++){
		st.empty();
		for(int i=step;i<=n;i++){
			while(!st.empty()){
				int a=st.top();
				if(a==pn[i]){
					for(int k=a;k<=i;k++){
						st.pop();
					}
					break;
				}
				st.push(pn[i]);
			}
		}
		while(!st.empty()){
			for(int j=1;j<=m;j++){
				nums[st.top()]++;
				st.pop();
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<nums[i]<<" ";
	}
	return 0;
	
}//ջ 
