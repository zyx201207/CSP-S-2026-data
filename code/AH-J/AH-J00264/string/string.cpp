#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a=0,b=0,c=0,t=0;
	string p;
	cin>>n;
	for(int i=1;i<=n;i++){
			int x;
			char y;
			cin>>x>>y;
			b+=x;
			for(int j=1;j<=x;j++){
				p+=y;
			}
	} 
	c=b/2;
	b--;
	for(int i=1;i<=c;i++){
		if(p[a]!=p[b]){
			t++;
		}
		a++,b--;
	}
	cout<<t;
}
