#include<bits/stdc++.h>
using namespace std;
int m[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=a;i++){
		cin>>m[i];
		if(m[i]<m[i-1]){
			return 0;
		}
	}
	for(int i=1;i<=a;i++){
		cout<<i<<" ";
	}

	return 0;
}
