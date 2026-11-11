#include<bits/stdc++.h>
using namespace std;
char a[10000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int tot=0;
	for(int i=1;i<=n;i++){
		int aa;
		char c;
		cin>>aa>>c;
		for(int j=1;j<=aa;j++){
			a[j+tot]=c;
		}tot+=aa;
	}
	int cur=0;
	for(int i=1;i<=tot/2;i++){
		if(a[i]!=a[tot-i+1]){
			cur++;
		}
	}cout<<cur<<endl;
	return 0;
}
