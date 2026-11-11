#include<bits/stdc++.h> 

using namespace std;
int a[500001];
int num;
int maxn;

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","W",stdout);
	
	long long n,m;\
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(m==0) break;
		if(num>=1) num=0;
		if(a[i]<a[i-1]){
			a[i]++;
			m--;}
		if(a[i]>a[i-1]) break;
		for(int j=1;j<=n;j++){
			if(a[j]==a[i]) num++;
			if(j==i) continue;}
		maxn=max(maxn,num);
		if(a[i]!=a[i-1]&&i!=1) i-=1;
	}
	cout<<maxn;
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
