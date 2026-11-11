#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000001];
int b[2000010];
set<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s.insert(0);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			if(s.count(a[j])){
				s.clear();
				s.insert(a[j]);
			}
			else{
				s.insert(a[j]); 
			}
		}
		for(auto t:s){
			for(int j=1;j<=m;j++){
				if(t==j){
					b[j]++;
				}
			}
		}
		s.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" "; 
	} 
}
