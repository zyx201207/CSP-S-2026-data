#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int a[n];
	char s[n];
	int f=0,b=n-1;
	long long ans=0;
	for(int i=0;i<n;i++) cin>>a[i]>>s[i];
	while(f<=b){
		if(s[f]==s[b]){
			if(a[f]>a[b]){
				a[f]-=a[b];
				b--;
			}
			else if(a[f]<a[b]){		
				a[b]-=a[f];
				f++;
			}
			else {
				f++;
				b--;
			}
		}
		else{
			if(a[f]>a[b]){	
				ans+=a[b];
				a[f]-=a[b];
				b--;
			}
			else if(a[f]<a[b]){			
				ans+=a[f];
				a[b]-=a[f];	
				f++;
			}
			else {
				ans+=a[f];
				f++;
				b--;
			}
		}		
	}
	cout<<ans;
	return 0;
} 
