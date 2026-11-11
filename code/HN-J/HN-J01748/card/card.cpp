#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[500005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f){
				q.push(a[j]);
				b[a[j]]=j;
				f=0;
			}
			else{
				for(int k=i;k<=b[a[k]];k++){
					cout<<a[k];
					q.pop();
				}
			}
		}
	}
	return 0;
}
