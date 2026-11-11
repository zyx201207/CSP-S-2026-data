#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a=0,b=0;
	int c[100001];
	cin>>a>>b;
	for(int i=0;i<a;i++){
	    cin>>c[i];
	}
	sort(c,c+a-1);
	for(int i=0;i<b-1;i++){
		c[a-1]=c[a-1]&c[a-2-i];
	}
	cout<<c[a-1];
	return 0;
}
