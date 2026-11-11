#include<bits/stdc++.h>
using namespace std;
char yuan[100000];
char xian[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int zz=0;
	while(t--){
		int a;
		char q;
		cin>>a>>q;
		for(int i=1;i<=a;i++){
			yuan[++zz]=q;
		}
	}
	int e=0;
	for(int i=zz;i>=1;i--){
		xian[++e]=yuan[i];
	}
	int x=1;
	int ans=0;
	while(zz--){
		if(xian[x]!=yuan[x]){
			ans++;
		}
	}
	if(ans==0){
		cout<<0;
	}else{
		cout<<ans/2;
	}
	return 0;
}
