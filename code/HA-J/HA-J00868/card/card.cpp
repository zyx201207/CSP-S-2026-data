#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],c[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t[a[i]]++;
		if(t[a[i]]>1){
			t[a[i]]--;
		}
		else 
			c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" "; 
	}
	return 0;
}
