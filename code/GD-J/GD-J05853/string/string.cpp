#include<bits/stdc++.h>
using namespace std;
long long cnt[2000005];
char a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>cnt[i]>>a[i];
		sum+=cnt[i];
	}
	if(sum%2==0){
		long long i=1,j=n;
		while(i<j){
			if(a[i]==a[j]){
				if(cnt[i]>cnt[j]){
					cnt[i]-=cnt[j];
					j--;
				}else if(cnt[i]<cnt[j]){
					cnt[j]-=cnt[i];
					i++;
				}else{
					i++;
					j--;
				}
			}else{
				if(cnt[i]>cnt[j]){
					ans+=cnt[j];
					cnt[i]-=cnt[j];
					j--;
				}else if(cnt[i]<cnt[j]){
					ans+=cnt[i];
					cnt[j]-=cnt[i];
					i++;
				}else{
					ans+=cnt[i];
					i++;
					j--;
				}
			}
		}
	}else{
		long long i=1,j=n;
		while(1){
			if(i==j) break;
			if(a[i]==a[j]){
				if(cnt[i]>cnt[j]){
					cnt[i]-=cnt[j];
					j--;
				}else if(cnt[i]<cnt[j]){
					cnt[j]-=cnt[i];
					i++;
				}else{
					i++;
					j--;
				}
			}else{
				if(cnt[i]>cnt[j]){
					ans+=cnt[j];
					cnt[i]-=cnt[j];
					j--;
				}else if(cnt[i]<cnt[j]){
					ans+=cnt[i];
					cnt[j]-=cnt[i];
					i++;
				}else{
					ans+=cnt[i];
					i++;
					j--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
