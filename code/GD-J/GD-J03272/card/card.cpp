#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50001],a1[50001]={0};
	int js[50002]={0};
	stack<int> s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a1[a[j]-1]==0){
				s.push(a[j]);
				a1[a[j]-1]++;
			}else{
				while(s.top()!=a[j]){
					s.pop();
				}
				a1[a[j]-1]=0;
			}
		}
		while(!s.empty()){
			js[s.top()]++;
			s.pop();
		}
	}
	for(int i=0;i<m;i++){
		cout<<js[i+1]<<' ';
	}
	return 0;
}
