#include<bits/stdc++.h>
using namespace std;
int a,b[500010],l[500010],ans[500010]={},a1;
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>a1;
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a;i++){
		memset(l,0,sizeof(l));
		for(int o=i;o<=a;o++){
			if(l[b[o]]==1){
				while(1){
					if(s.top()==b[o]){
						l[b[o]]=0;
						s.pop();
						break;
					}
					l[s.top()]=0;
					s.pop();
				}
				s.push(b[o]);
				l[b[o]]=1;
			}
			else{
				s.push(b[o]);
				l[b[o]]=1;
			}
		}
	    while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=a1;i++){
		cout<<ans[i]<<" ";
	}
}
