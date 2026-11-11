//GZ-J00141 自强中学 赵浩然 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
queue <int>a;
queue <int>b;
void rule(){
	
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		b.push(x);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			a.push(b.front());
			
		}
		
		
		b.pop();
	} 
	
	
	return 0;
}
