#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,a[200005],s[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		s[i]=s[i-1]+a[i];
	}
	long long b=0;
	int x=0;
	while(b<=sum/2){
		b+=a[++x];
	}
	
	//cout<<x<<endl;
	int l=1,r=n;
	while(l<=x && r>=x){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r--]; 
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l++];
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}
		}
		//cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	
	cout<<ans<<endl;
	return 0;
}
