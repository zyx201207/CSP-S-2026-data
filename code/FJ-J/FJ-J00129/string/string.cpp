#include<bits/stdc++.h>
using namespace std;
int n,a[100024],r;
long long ans;
char b[100024];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	r=n;
	long long w=0,s=0;
	for(int i=1;i<=n;i++){
		w=a[i];
		if(s>0){
			if(w>=s){
				w-=s;
				if(b[r]!=b[i]){
					ans+=s;
				} 
				r--;
			} 
			else{
				if(b[r]!=b[i]){
					ans+=w;
				}
				continue;
			}
		}
		
		for(int j=r;j>=i;j--){
			if(b[j]!=b[i])ans+=a[j];
			if(a[j]<w)w-=a[j];
			else if(a[j]==w){
				w-=a[j];
				break;
			}
			else{
				if(b[j]!=b[i])ans-=a[j];
				s=a[j]-w;
				break;
			}
			r=j;
			if(j==i){
				break;
			}
		}
		if(r==i)break;
	}
	cout<<ans;
}
