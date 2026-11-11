#include<bits/stdc++.h>
using namespace std;
stack<int> s; 
stack<int> s2;
const int N=5*1e5+10;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		s.push(a[i]);
		for(int j=i+1;j<n;j++){
			bool f=0;
			while(!s.empty()&&s.top()!=a[j]){
				s2.push(s.top());
				s.pop();
			}
			if(s.empty()) f=1;
			if(f){
				while(!s2.empty()){
					s.push(s2.top());
					s2.pop();
				}
				s.push(a[j]);
			}
			else{
				while(!s2.empty()){
					s2.pop();
				}
			}
			
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
return 0;
} 
