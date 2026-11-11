#include<bits/stdc++.h>
using namespace std;
long long n,d;
int ac,cnt;
int a[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,t=0;
	cin>>c;
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[j]-a[i]>d&&(a[j]-a[i])%2==1&&(a[j]-a[i])%d==1){
					for(int m=i;m<j;m++){
						if(a[m+1]-a[m]>=d){
							ac=1;
						}
					}
					if(ac==0){
						cnt++;
					}
					ac=0;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}

