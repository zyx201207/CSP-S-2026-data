#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+2;
int n,m;
int a[MAX],b[MAX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		if(a[i-1]==a[i+1])b[a[i]]--;
		else if(a[i-2]==a[i+2]){
			b[a[i-1]]--;
			b[a[i]]--;
			b[a[i+1]]--;
		}
	}
	for(int i=1;i<=m;i++){
	    cout<<b[i]<<" ";    	
	}
	return 0;
}
