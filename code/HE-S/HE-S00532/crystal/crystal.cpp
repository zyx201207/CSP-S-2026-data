#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[1000010]={0};
int b[1000010]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fclose(stdin);
	sort(a+1,a+1+n);
	int maxd=0;
	for(int i=1;i<=n;i++){
		int md=m;
		int l=i;
		int all=0;
		int newd=i;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		while(true){
			if(l==n&&b[i]==b[newd]){
				break;
			}
			if(b[l+1]-b[l]==0){
				l++;
				continue;
			}
			else if((b[l+1]-b[l])<=md){
				md-=(b[l+1]-b[l]);
				b[l]=b[l+1];

				l++;
				if(l!=i+1&&b[i]!=b[newd]){
					l=i;
				}
			}
			else{
				break;
			}
			if(l>newd){
				newd=l;
			}
		}
		int q=b[i];
		int p=b[newd];
		if(q==p){
			all+=(newd-i+1);
			for(int j=newd+1;j<=n;j++){
				if(b[j]!=b[newd]){
					break;
				}
				all++;
			}
		}
		else{
			int q=0;
			int p=0;
			for(int j=i;j<=newd;j++){
				if(b[j]!=b[i]){
					break;
				}
				q++;
			}
			for(int j=i;j<=newd;j++){
				if(b[j]==b[newd]){
					p++;
				}
			}
			all=max(q,p);
		}
		maxd=max(maxd,all);
	}
	cout<<maxd;
	fclose(stdout);
	return 0;
} 
