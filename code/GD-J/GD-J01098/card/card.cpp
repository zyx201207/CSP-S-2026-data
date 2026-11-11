#include<bits/stdc++.h>
using namespace std;
stack<int>s; 
int n,m;
int a[100003],b[100003],c[100003];
void ans(){
	for(int i=1;i<=m;i++){
		if(a[i]){
			b[i]++;
			
		}
	}
}
void chack(int y){
	for(int i=y;i<=n;i++){
		if(a[c[i]]==0){
			s.push(c[i]);
			a[c[i]]++;
		}else{
			while(c[i-1]!=s.top()){
				s.pop();
				a[s.top()]=0;
			}
			a[c[i]]=1;
		}	
	}
	ans();
	

}
void clean(){
	while(!s.empty()){
		s.pop();
	}
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){	
		cin>>c[i];
		
	}
	for(int i=1;i<=n;i++){
		clean();
		chack(i);
		
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
	
} 
