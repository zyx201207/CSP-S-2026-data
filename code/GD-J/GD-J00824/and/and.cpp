#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
			cout<<sum<<" ";
		}
		cout<<endl<<sum;
		return 0;
	}else if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		cout<<maxn;
	}else if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ss=a[i]&a[j];
				if(maxn<ss){
					maxn=ss;
				}
			}
		}
		cout<<maxn;
	}else if(m==3){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					int ss=a[i]&a[j]&a[z];
					if(maxn<ss){
						maxn=ss;
					}
				}
			}
		}
		cout<<maxn;
	}
	else if(m==4){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int b=z+1;b<=n;b++){
						int ss=a[i]&a[j]&a[z]&a[b];
						if(maxn<ss){
							maxn=ss;
						}
					}
				}
			}
		}
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
