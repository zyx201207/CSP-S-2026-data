#include <bits/stdc++.h>
using namespace std;
int a[200000],b[200000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
for(int i=0;i<n;i++){
	int k=1;
	for(int j=i;j<=n;j++){
	int q;
	for(q=1;q<k;q++){
	if(b[q]==a[j]){
		for(int p=q;p<k;p++){
	b[p]=0;
}
break;
	}
		}
		k=q;
		b[k]==a[j];
		k++;
	}


cout<<a[i]<<b[k];
}
	return 0;
} 
