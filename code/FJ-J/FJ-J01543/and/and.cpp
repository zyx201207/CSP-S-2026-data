#include<bits/stdc++.h>
using namespace std;
int n,k,ans,arr[200005],f[200005][51],s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		int p=arr[i],cnt=0;
		while(p){
			if(p%2==1){
				f[0][cnt]++;
				f[i][cnt]=1;
			}
			p/=2;
			cnt++;
		}
	}
	bool flag=0;
	for(int i=40;i>=0;i--){
		if(f[0][i]>=k){
			if(flag==0){
				ans=pow(2,i);
				flag=1;
				for(int j=1;j<=n;j++){
					if(f[j][i]==1) s[j]=1;
				}
			}else{
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(f[j][i]==1 && s[j]) cnt++;
				}
				if(cnt>=k){
					ans+=pow(2,i);
					for(int j=1;j<=n;j++){
						if(f[j][i]==0 && s[j]) s[j]=0;
					}
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
