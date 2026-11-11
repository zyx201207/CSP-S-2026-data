#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)return cout<<0,0;
	if(n==2){
		int a,b;
		char c,d;
		cin>>a>>c>>b>>d;
		if((int)c==(int)d)return cout<<0,0;
		else return cout<<min(a,b),0;
	}
	char b[200005];
	int a[200005];
	bool t=true;
	cin>>a[1]>>b[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1]){
			t=false;
			break;
		}
	}
	if(t)cout<<0;
	else cout<<a[1];
    return 0;
}
