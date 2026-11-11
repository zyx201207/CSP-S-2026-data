#include<bits/stdc++.h>
using namespace std;
int  x[1005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;int m;int sz=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
		if(x[i]>sz){
			sz=x[i];
			}
		}
		cout<<sz;
	return 0;
	}
