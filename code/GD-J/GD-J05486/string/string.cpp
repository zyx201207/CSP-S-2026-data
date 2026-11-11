#include<bits/stdc++.h>
using namespace std;

long long n,s[200005];
char z[200005];
string x;
struct K{
	 int zs;
	 char zm,dm;
};
long long b(string c){
	string k;
	K P[100000000];
	char p;
	long long l=c.size(),m=1,e=0;
	if(l%2==0){
		p=c[l/2];
	}else{
		p=c[l/2+1];
	}
	for(int i=0;i<p;i++){
		if(s[i]==s[l-1-i]){
			continue;
		}else{
			P[m++].zm=s[i];
			s[i]=' ';
			P[m].dm=s[l-1-i];
		}
	}
	for(int i=1;i<m;i++){
		e=0;
		for(int j=0;j<i||e!=0;j++){
			if((P[i].dm==P[j].zm)&&(P[j].dm==P[i].zm)){
				m--;
				e=1;
			}
		}
	}
	return m;
}
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>s[i]>>z[i];
		for(int j=1;j<=s[i];j++){
			x+=z[i];
		}
	}
	cout<<b(x);	
	
}
