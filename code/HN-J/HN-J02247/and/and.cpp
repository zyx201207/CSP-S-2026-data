#include <bits/stdc++.h>
using namespace std;
int n,m,c,t,a[200010],h[200010],s;
string b[200010];
bool f=false;
string two(int p){
	string x;
	c=0;
	while(p>1){
		x[c]=p%2;
		p=p/2;
		c++;
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >>m;
	int o=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		for(int j=0;j<=o;j++){
			if(a[i]<a[j]){
				int d=a[i];
				a[i]=a[j];
				a[j]=d;
			}
		}
		o++;
	}
	for(int i=n;i>=n-m;i--){
		b[i]=two(a[i]);
		if(f==false){
			t=c;
			f=true;
		}
	}
	for(int i=t;i>=0;i--){
		for(int j=n;i>=n-m;i--){
			if(b[j][i]=='0'){
				h[i]=0;
				f=false;
			}
		}
		if(f==true){
			h[i]=1;
		}
		f=true;
	}
	int q=1;
	for(int i=t;i>=0;i--){
		s=s+h[i]*q;
		q=q*2;
	}
	cout <<s;
	return 0;
} 
