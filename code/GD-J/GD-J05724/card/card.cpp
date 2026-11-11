#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[50001],b[50001];
    bool x[50001];
    stack<int> s;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		x[i]=true;
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			if(!x[a[j]]){
				s.pop();
				while(s.top()!=a[j]){
					s.pop();
				}
			}		
		    x[s.top()]=false;
		}
		for(int j=1;j<=m;j++){
			x[j]=true;
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}

	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
