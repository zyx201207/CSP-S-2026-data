#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long b[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		queue<int>s;
		for(int j=i;j<n;j++){
			queue<int>z;
			while(!s.empty()){
				if(a[j]==s.front()){
					while(!s.empty()){
						s.pop(); 
					}
				}else{
					z.push(s.front());
					s.pop();	
				}	
			}
			while(!z.empty()){
				s.push(z.front());
				z.pop();
			}
			s.push(a[j]);
		} 
		while(!s.empty()){
			b[s.front()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
		
	}
	return 0;
}
