#include<bits/stdc++.h> 
using namespace std;
long long n,a[100000],cnt=0,ans=0,t=0,j=0,q=0;
string c[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(long long i=0;i<cnt/2;i++){
		if(i==0){
			t=max(a[j],a[n-j-1])-min(a[j],a[n-j-1]);
			if(c[j]!=c[n-j-1]) ans+=min(a[j],a[n-j-1]);
			i+=min(a[j],a[n-j-1])-1;
			q=n-j-1;
			if(a[j]<a[n-j-1]){
				a[n-j-1]-=t;
				j++;
			} 
			else if(a[j]>a[n-j-1]){
				q-=1;
				a[j]-=t;
			}
			else{
				q-=1;
				j++;
			}
		}
		if(j>q) break;
		else{
			i+=min(a[j],a[q])-1;
			if(c[j]!=c[q]) ans+=min(a[j],a[q]);
			t=max(a[j],a[q])-min(a[j],a[q]);
			if(a[j]<a[q]){
				j++;
				a[q]-=t;
			} 
			else if(a[j]>a[q]){
				q-=1;
				a[j]-=t;
			}
			
			else{
				q-=1;
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
