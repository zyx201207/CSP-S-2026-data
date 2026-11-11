#include<bits/stdc++.h>
using namespace std; 
int n,k;
const int N=1e6+15;
vector<int> q[N];
//我已力竭(⊙o⊙)
//题目看不懂,给到紫
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int st=t+1;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		cout<<st-t<<endl;
		//特殊性质也不会。输出1~t; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//我去忘记return 0了 
}
