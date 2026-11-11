#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int ans=0;
	for(int i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				j--;	
			}
		}else if(a[i]==a[j]){
			if(c[i]==c[j]){
				j--;i++;
			}else{
				ans+=a[j];
				i++;j--;	
			}
		}else{
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				i++;	
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
