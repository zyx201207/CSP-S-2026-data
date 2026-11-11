#include<bits/stdc++.h>
using namespace std;
long long b[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int d,t;
	cin>>d>>t;
	for(int c=0;c<t;c++){
		long long n,d;
		cin>>n>>d;
		long long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				long long cnt=0;
				if(a[j]-a[i]>d*2){
					break;
				}
				if(a[j]-a[i]<=d){
					continue;
				}
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]>d){
						break;
					}
					if(a[j]-a[k]<=d){
						cnt++;
						if(cnt>2){
							break;
						}
					}
				}
				if(cnt==2){
					b[c]++;
				}
			}
		}
	}
	for(int c=0;c<t;c++){
		cout<<b[c]<<endl;
	}
	return 0;
}
