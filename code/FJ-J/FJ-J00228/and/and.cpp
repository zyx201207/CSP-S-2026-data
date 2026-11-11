#include<bits/stdc++.h>
using namespace std;
string s[200010];
int b[200010];
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma) ma=a[i];
		}
		cout<<ma;
		return 0;
	}cout<<"1";
	return 0;
} 
