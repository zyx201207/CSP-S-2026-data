#include<bits/stdc++.h> 
using namespace std;
int n,m,b[500009],ans[500009],l,k;
bool c[300009];
stack <int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			k=b[j];
			if(c[k]){
				while(a.top()!=k){
					c[a.top()]=0;
					a.pop();
				} 
			}
			else{
				c[k]=1;
				a.push(k);
			} 
		}
		for(int j=1;j<=m;j++){
			if(c[j]) ans[j]++;
		}
		for(int j=1;j<=m and !a.empty();j++){
			a.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
