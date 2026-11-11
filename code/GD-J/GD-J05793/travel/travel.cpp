#include<bits/stdc++.h>
using namespace std;
long long a,c,e,g;
int l,m;
char i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>i;
	cin>>e>>g>>j;
	if(a==e){
		cout<<1;
	}
	else cout<<0;
	
	if(c==g&&a==e){
		cout<<1;
	}
	if(c!=g||a!=e){
		cout<<0<<0<<0;
		return 0;
	}
	l=(int)i;
	m=(int)j;//
	int n,o;
	if(l>=m){
		n=l;
	}else n=m;
	if(l<=m){
		 o=l;
	}else o=m;
	if(n==69&&o==68&&c==g&&a==e){
		cout<<1;
	}else
	if(n-o<3&&n!=69&&n!=68){
		cout<<1;
	}else cout<<0;
	if(n-o==1&&n!=69&&n!=68&&c==g&&a==e){
		cout<<1;
	}else cout<<0;
	return 0;
} 


























































