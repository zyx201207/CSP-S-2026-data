#include<bits/stdc++.h>
using namespace std;
stack<int>p;
	int a[340434]={};
	int b[340434]={};
	int c[240434];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[c[j]]==1){
				for(int w=1;w<=p.size();w++){
					b[p.top()]=0;
					if(p.top()==c[j]){
						p.pop();
						break;
					}
					p.pop();
				
				}
			}
			b[c[j]]++;
			p.push(c[j]);
		}
		for(int g=1;g<=p.size();g++){
			p.pop();
		}
		for(int v=1;v<=3006;v++){
			
			a[v]+=(b[v]>=1);
			b[v]=0;
		}
	}
	for(int i=1;i<=m;i++){

			cout<<a[i]<<' ';
		
	}
	return 0;
}
