#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[500005];
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack <int> s;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (b[a[j]]){
			    while (s.top()!=a[j]){
				    b[s.top()]=false;
				    s.pop();
			    }    
		    }
		    else {
			    s.push(a[j]);
			    b[a[j]]=true;
		    }
		}
		for (int k=1;k<=m;k++){
			if (b[k])  x[k]++;
		}
		while (s.size())  s.pop();
		for (int i=1;i<=m;i++)  b[i]=false;
	}
	for (int i=1;i<=m;i++)  cout<<x[i]<<" ";
}
