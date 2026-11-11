//GZ-S00131 张栋皓 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
long long n,ans;
long long m;
long long a[500010],k[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		k[i]=k[i-1]+(a[i]-a[i-1]);
	}
	for(long long i=0;i<n;i++){
		long long j=0;
		long long cnt=0;
		for(j=i+1;j<n;j++){
		    cnt+=k[j]-k[i];
    		if(cnt>=m){
    			j--;
				break; 
			}
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
