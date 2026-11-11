#include<bits/stdc++.h>
using namespace std;
long long n,m,T;
long long c[300000];
long long t[300000];
long long f[300000];
int j[300000];
int check(int a,int k){
	for(int i=1;i<k;i++){
		if(f[i]==a)return i;
	}
	return 0;
}
void sha(int l,int k){
	for(int i=l;i<k;i++){
		f[i]=0;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(T=1;T<=n;T++){
		int l=0;
		f[n-T+2]=0;
		for(int i=T;i<=n;i++){
			f[++l]=c[i];
			int s=check(f[l],i);
			if(s){
				sha(s,l);
			}
		}
		for(int i=1;i<=n-T+1;i++){
			if(j[f[i]]==0){
				t[f[i]]++;
				j[f[i]]++;
			}	
		}
		for(int i=1;i<=m;i++)j[i]=0;
	}
	
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}


	return 0;
}

