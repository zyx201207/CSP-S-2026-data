#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n+3],c[m+3]={0},d[m+3]={0};
	
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			stack<int>a;
			if(c[b[j]]==1){
				while(a.top()==b[j]){
					c[a.top()]--;
					a.pop();
				}
			}else{
				c[b[j]]++;
				a.push(b[j]);
			}
		}
		for(int f=1;f<=n;f++){
			d[f]+=c[f];
			c[f]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
