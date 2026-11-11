#include<bits/stdc++.h>
using namespace std;
int n,l,cnt,z;
string a,b,c;
bool p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>z>>c;
	b=c;
	for(int i=2;i<=n;i++){
		int x=0;
		string y=0;
		scanf("%d",&x);
		cin>>y;
		if(b!=y){
			p=1;
		}
		cnt+=x;
		if(x>l){
			l=x;
		}
		while(x>0){
			a+=y;
			x--;
		}
	}
	if(z>l){
		l=z;
	}
	if(p==1){
		cout<<cnt+z-l<<'\n';
		return 0;
	}
	cout<<0<<'\n';
	return 0;
}
