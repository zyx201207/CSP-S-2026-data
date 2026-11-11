#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d[500005],e;
queue<int> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				c.push(j);	
			}else{
				while(true){
					if(c.back()==a[j]){
						c.pop();
						break;
					}b[c.back()]=0;
					c.pop();
				}c.push(a[j]);
			}
		}e=c.size();
		for(int j=0;j<e;j++){
			d[c.back()]++;
			cout<<c.back();
			c.pop();
		}
	}for(int i=1;i<=m;i++)cout<<d[i]<<' ';
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
