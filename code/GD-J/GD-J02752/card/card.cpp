#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	stack<int> s;
	int a[10001],b[10001],c1=0,a1=0,c[10001];
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		b[i]=c;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<a1;k++){
				if(b[j]==a[i]){
					while(s.top()==b[j]){
						s.pop();
						a1--;
					}
					s.pop();
				}
			}
			s.push(b[j]);
			a[a1]=b[j];
			a1++;
		}
		while(!s.empty()){
			c[s.top()]++;
			s.pop();
		}
	}
	for(int i=0;i<m;i++){
		if(c[m]==0){
			continue;
		}
		cout<<c[m]<<" ";
	}
	return 0;
} 
