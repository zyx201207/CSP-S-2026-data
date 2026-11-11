#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	int n,m;
	fin>>n>>m;
	//cin>>n>>m;//
	for(int i=1;i<=n;i++){
		fin>>a[i];
		//cin>>a[i];//
	}
	
	if(m==1){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=max(ans,a[i]);
		fout<<ans;
	}
	else if(m==2){
		long long ans=a[1]&a[2];
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		fout<<ans;
	}
	else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		fout<<ans;
	}
	else if(m==n-1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			long long anss=-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(anss=-1){
						anss=a[j];
					}
					else{
						anss=anss&a[j];
					}
				}
			}
			ans=max(ans,anss);
		}
		fout<<ans;
	}
	else{
	int k=n,t=0;
	while(k%2==0&&k>0){
		k=k/2;t++;
	}
	if(k==0){
		fout<<t-1;
	}
	else{
		for(t=1;t<=n;t++) if(a[t]>4) break;
	if(t==n+1){
		int b[5];
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=4;i>=1;i--){
			if(b[i]>=2){
				fout<<i;
				break;
			}
		}
	}
	else{
		for(t=1;t<=n;t++) a[t]++;
		int maxx=-1;
		for(int i=1;i<=n;i++){
			int j=0,x=a[i];
			while(x>0) {
				x=x/2;j++;
	}
	maxx=max(j,maxx);
	}
	fout<<maxx;
	}
	}
	}
	fin.close();
	fout.close();
} 
