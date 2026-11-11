#include<bits/stdc++.h>
using namespace std;
int a[200000];
bool b1[32],b2[32];
int awy(int a,int b){
	int aa=a,bb=b,j1=0,j2=0;
	while(aa){
		j1++;
		b1[j1]=aa%2;
		aa/=2;
	}
	while(bb){
		j2++;
		b2[j2]=bb%2;
		bb/=2;
	}
	for(int i=0;i<=max(j1,j2);i++){
		if(b1[i]==1&&b2[i]==1){
			b1[i]=1;
		}
		else{
			b1[i]=0;
		}
	}
	int sum=0,ch=1;
	for(int i=1;i<=max(j1,j2);i++){
		if(b1[i]){
			sum+=ch;
		}
		ch*=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int ans=awy(a[1],a[2]);
		for(int i=3;i<=n;i++){
			ans=awy(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==(n-1)){
		int maxn=0,ans;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==1){
					int ans=awy(a[2],a[3]);
					for(int i=4;i<=n;i++){
						if(j!=i){
							ans=awy(ans,a[i]);
						}
					}
					if(ans>maxn){
						maxn=ans;
					}
				}
				else if(i==2){
					int ans=awy(a[1],a[3]);
					for(int i=4;i<=n;i++){
						if(j!=i){
							ans=awy(ans,a[i]);
						}
					}
					if(ans>maxn){
						maxn=ans;
					}
				}
				else{
					int ans=awy(a[1],a[2]);
					for(int i=3;i<=n;i++){
						ans=awy(ans,a[i]);
					}
					if(ans>maxn){
						maxn=ans;
					}
				}
			}
			
		}
		cout<<maxn;
	}
	return 0;
}
