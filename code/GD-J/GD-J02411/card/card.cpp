#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
bool vis[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int x=a[j];
			if(!vis[x]){
				//cout<<a[j]<<'\n';
				s.push(x);
				vis[x]=1;
			}else{
				while(!s.empty()&&s.top()!=x){
					if(s.top()==x){
						break;
					}
					//cout<<s.top()<<' '<<a[j]<<' ';
					vis[s.top()]=0;
					s.pop();
				}//s.push(a[j]);
				//cout<<'\n';
			}
		}
		//cout<<'\n';
		//cout<<"ПеЃП"<<s.empty(); 
		while(!s.empty()){
			//cout<<s.top()<<' ';
			t[s.top()]++;
			s.pop();
		}//cout<<'\n';
		memset(vis,0,sizeof vis);
	}
	for(int i=1;i<=m;i++){
		//if(t[i]){
		cout<<t[i]<<' ';
		//}
	}
	return 0;
} 
