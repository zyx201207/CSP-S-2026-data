#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    map<int,int> c;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	c[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int x=1;
		for(int j=c[i]-1;j>=0;j--){
			if(c[a[j]]!=j&&a[j]!=a[c[i]]){
				if(c[a[j]]>c[i]){
					cout<<c[i]-j<<" ";
					x=0;
					break;
				}
			}	
		}
		if(x==1){
			cout<<c[i]+1<<" ";
		}
	}
	return 0;
}
