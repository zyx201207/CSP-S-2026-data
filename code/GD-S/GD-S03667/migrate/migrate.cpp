#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,s=1;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=2;j<n;j++){
			s=1;
			for(int k=1;k<n;k++){
				if(a[k]-a[j-s]>=0&&a[k]-a[j-s]<=d){
					b[i]++;
				}else if(a[k]-a[j-s]<0&&0-(a[k]-a[j-s])<=d){
					b[i]++;
				}
				s++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}
