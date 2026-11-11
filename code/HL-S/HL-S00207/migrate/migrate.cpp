#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
long long c[200010];

int check(int g,int h,int d){
	if(h-g>=2*d){
		return 0;
	}
	int cnt=0;
	for(int i=g+1;i<h;i++){
		for(int j=i+1;j<h;j++){
			if(a[j]-a[g]<=d){
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdin);
	int ty,t;	cin>>ty>>t;
	while(t--){
		long long cnt=0; 
		int n,d;
		cin>>n>>d;
		int l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=min(n,i+2*d-1);j++){
				int u=check(i,j,d);
				if(u){
					int flag=1;
					for(int g=1;g<=l;g++){
						if(b[g]==i&&c[g]==j){
							flag=0;
							break;
						}
					}
					if(flag){
					l++;
					b[l]=i;
					c[l]=j;
					}
				}
			}
		}
		cout<<l<<endl;
	}
	return 0;
} 
