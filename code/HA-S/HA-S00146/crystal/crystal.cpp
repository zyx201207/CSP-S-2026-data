#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m; 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	long long sb=0;
	sort(a+1,a+n+1);
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<i;j++){
			cnt+=a[i]-a[j];
			if(cnt>m){
				for(long long x=1;x<=n;x++){
					if(x<=i-1){
						b[x]=a[i-1];
					}
					else{
						for(long long z=i;z<=n;z++){
							b[z]=a[z];
						}
					}
				}
				for(long long y=1;y<=n;y++){
					if(b[y]==b[y+1] and b[y]!=0){
						sb+=1;
					}
				}
				cout<<sb+1;
				return 0;
			}
		}
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
