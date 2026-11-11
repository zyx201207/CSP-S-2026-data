#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],lt,l;
string b,c;
string f(int x){
	while(x!=0){
		int z=0;
		c[z]+=x%2;
		z++;
	}
	return c;
}
int w(string x,string y){
	string d;
	int g;
	for(int i=0;i<=max(x.size()-1,y.size()-1);i++){
		if(x[i]==y[i]){
			d[i]=1;
		}
		else{
			d[i]=0;
		}
	}
	for(int i=d.size()-2,y=1;i>=0;i--,y++){
		g+=d[i]*(2*y);
	}
	return g+d[d.size()-1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int t=0;
		while(m>0){
			int h=0;
			t+=w(f(a[i+h]),f(a[i+1+h]));
			h++;
			m--;
		}
		if(t>l){
			l=t;
		}
	}
	cout<<l<<'\n';
	return 0;
}

