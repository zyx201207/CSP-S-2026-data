//GZ-S00164 黔南布依族苗族自治州都匀第一中学 廖梓淳 
#include<bits/stdc++.h>
using namespace std;
int n,m,mid,ans=0;
int f[500010];
int main(){
	int y,w;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d ",&f[i]);
	    }
	mid=(n-1)/2;
	    for(int j=mid-1;j>0;j--){
		    if (f[j]==f[mid]);
		    ans++;
		    if (f[j]<f[mid]);
		        for(y=0;y<m;y++){f[j]=f[j]+y;w=m-y-1;}
		        if (f[j]==f[mid]);
			         ans++;
		    }
	            for(int g=0;g<n-mid-1;g++){
	                if (f[mid]=f[mid+g]);
		            ans++;
		            }
	printf("%d",ans);
	return 0;
}
