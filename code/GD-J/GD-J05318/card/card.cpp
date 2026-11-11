#include<bits/stdc++.h>
using namespace std;
int n,m,t;
stack <int> a;
vector <int> c;
int b[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int o=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(c[k]==b[j]){
					t++;
					break;
				}
			}
			if(t==1){
				for(int k=1;k<=n;k++){
					if(a.top()!=b[j]){
						a.pop();
					}
					else if(a.top()==b[j]){
						a.pop();
						a.push(b[j]);
						break;
					} 
				}
			}
			else{
				a.push(b[j]);
				c.push_back(b[j]);
			}
		}
		for(int j=1;j<=a.size();j++){
			d[a.top()]++;
			o++;
			a.pop();
		}
	}
	for(int i=1;i<=o;i++){
		cout<<d[i];
	}
	return 0;
} 
