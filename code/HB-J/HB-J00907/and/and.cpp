#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and1.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,p=0,l=1,c,f,n,m[100],q[100],g=0;
	cin>>a>>c;
	for(int i=1;i<=100;i++){q[i]=1;}
	long long e[10000];
	for(long long i=1;i<=a;i++){
		cin>>n;
		e[i]=n;
	}
	for(long long j=a;j>=1;j--){
		for(long long i=1;i<j;i++){
			if(e[i]<=e[i+1]){
				f=e[i];
				e[i]=e[i+1];
				e[i+1]=f;
			}
		}
	}
	for(long long i=1;i<=c;i++){
		g=0;
		while(e[i]>=1){
			g++;
			m[i]=e[i]%2;
			if(q[g] && m[i]){q[g]=1;}
			else{q[g]=0;}
			e[i]/=2;
		}
		for(int j=g+1;j<=100;j++){q[j]=0;}
	}
	for(long long i=g;i>=1;i--){
		l=1;
		for(long long j=1;j<i;j++){l*=2;}
		p+=q[i]*l;
	}
	cout<<p;
	return 0;
}
