#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int fin=0;
	for(int i=1;i<=n;i++){
		int ans=a[i] & a[i+1];
		if(ans>fin){
			fin=ans;
		}
	}
	cout<<fin;
    return 0;
 }
 
