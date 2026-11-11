#include<bits/stdc++.h>

using namespace std;
long long a[3000010],b[3000010];
char c[3000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=c[i]-'a'+1;
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;	
			}else{
				a[r]-=a[l];
				l++;	
			}
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;	
			}else{
				a[r]-=a[l];
				l++;	
			}
		}	
		
	}
	cout<<ans;
	return 0;
}
