#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[500010];
	int b[500010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[a[i]]++;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				b[a[i]]=1;
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
