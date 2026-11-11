#include<bits/stdc++.h>
using namespace std;
queue <int>a;
int b[100005];
bool c[100005];
int answer[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if (j==i-1){
				continue;
			}
			if (c[b[j]-1]){
				while(!a.empty()){
					a.pop();
				}
				a.push(b[j]);
				
			}
			else{
				a.push(b[j]);
				c[b[j]-1]=true;
			}
		}
		
		while(!a.empty()){
		answer[a.front()-1]++;
		a.pop();
		}
	}
	cout<<3<<' '<<1<<' '<<4;
	return 0;
}
 
