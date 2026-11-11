#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	} 
	for(int i=0;i<n;i++){
		if(b[a[i]]>1){
			b[a[i]]=0;
			for(int j=n;j>=i;j++){
				b[a[i]]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<b[a[i]];
	}
	return 0;
}

