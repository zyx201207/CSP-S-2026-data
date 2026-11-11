#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005]; 
bool bin[300005];
stack<int>s,iis/*Int Input Stack*/;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	while(n--){
		int i;
		cin>>i;
		iis.push(i);
	}
	while(iis.size()){
		int i=iis.top();
		iis.pop();
		if(bin[i]){
			while(s.top()!=i){
				bin[s.top()]=false;
				ans[s.top()]-=iis.size();
				s.pop();
			}
		}else{
			s.push(i);
			bin[i]=true;
			ans[i]+=iis.size();
		}
	}
	while(s.size()){
		ans[s.top()]++;
		s.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
//3>4
