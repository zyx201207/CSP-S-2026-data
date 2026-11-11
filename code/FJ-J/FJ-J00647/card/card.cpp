#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
stack<int>s;
map<int,int>ma;
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			stack<int>s1=s;
			bool op=0;
			while(!s1.empty()){
				if(s1.top()!=a[j]){
					s1.pop();
				}
				else{
					op=1;
					break;
				}
			}
			if(op==0){
				s.push(a[j]);
			}
			else{
				s=s1;
			}
		}
		while(!s.empty()){
			ma[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ma[i]<<" ";
	}
} 
