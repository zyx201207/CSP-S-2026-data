#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[200001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if(a[j]==a[i]){
				cnt++;
			}
		}
		cout<<cnt<<" ";
		cnt=0;
	}
	

	return 0;
}
