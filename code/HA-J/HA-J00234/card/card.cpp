#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1000005];
int f[1000005];
int t[1000005];
int r=0;
void csh(){
	memset(b,0,sizeof(0));
	r=0;
}
void add(int x){
	b[r]=x;
	r++;
}
int jc(int x){
	for(int i=0;i<=r;i++){
		if(b[i]==x){
			return i;
		}
	}
	return -1;
}
void qc(int x){
	for(int i=x;i<=r+1;i++){
		b[i]=0;
	}
	r=x;
}
void tg(){
	for(int i=0;i<n;i++){
		f[i]=f[i+1];
	}
	n--;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	while(n>0){
		csh();
		for(int j=0;j<n;j++){
			if(jc(f[j])!=-1){
				qc(jc(f[j]));
			}
			add(f[j]);
		}
		for(int i=1;i<=m;i++){
			if(jc(i)!=-1){
				t[i]++;
			}
		}
		tg();
	}
	for(int i=1;i<=m;i++){
			cout<<t[i]<<' ';
	}
	return 0;
}
