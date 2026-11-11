#include<bits/stdc++.h>
using namespace std;
struct node{
	int m;
	char c;
}a[3000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	if(n==1){
		cout<<"0";
	}
	else if(n==2){
		if(a[1].c==a[2].c){
			cout<<"0";
			return 0;
		}
		cout<<min(a[1].m,a[2].m);
	}
}
