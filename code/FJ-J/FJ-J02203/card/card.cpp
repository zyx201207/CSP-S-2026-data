#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(num[a[i]]==0)   num[a[i]]=i;
	}
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			
		}
		cout<<num[a[i]];
	}
	
	return 0;

}
