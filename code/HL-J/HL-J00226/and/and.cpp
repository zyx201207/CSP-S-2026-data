#include<bits/stdc++.h>
using namespace std;
int idx=0;long long f[1000][2],d[1000][2],n,m;
void js(int a){
	int p=0;
	while(a>0){
		int h=a%2;
		f[p][h]++;
		if(!d[p][h])d[p][h]=++idx;
		p=d[p][h];
		a/=2;
	}
} 
long long fin(int a){
	int p=0;
	long long w=1,s=0;
	while(a>0){
		int h=a%2;
		if(f[p][h]>=m)s+=h*w;
		w*=2;
		p=d[p][h];
		a/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long a1[210000]={},s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i];
		js(a1[i]);
		s=max(s,fin(a1[i]));
	}
	cout<<s;
	return 0;
}
