#include<bits/stdc++.h>
using namespace std;
int n,m,a[200004],ans,mx,s1,s2;
int p[105],q[105],k[105];
void turn1(int b){
	for(int i=1;b>=1;i++){
		p[i]=b%2;
		b/=2;
		s1=i;
	}
}
void turn2(int c){
	for(int i=1;c>=1;i++){
		q[i]=c%2;
		c/=2;
		s2=i;
	}
}
void yh(){
	for(int i=1;i<=max(s1,s2);i++){
		if(p[i]==q[i])k[i]=1;
		else{
			k[i]=0;
		}
	}
}
void clean (){
	for(int i=1;i<=100;i++){
		p[i]=0;
		q[i]=0;
		k[i]=0;
	}
}
void turn3(){
	int d=1;
	ans=0;
	for(int i=1;i<=max(s1,s2);i++){
		ans+=k[i]*d;
		d*=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		turn1(a[i]);
		for(int j=1+i;j<n;j++){
			turn2(a[j]);
			yh();
			turn3();
			mx=max(ans,mx);
		}
	}
	}
	
	cout<<mx;
}
