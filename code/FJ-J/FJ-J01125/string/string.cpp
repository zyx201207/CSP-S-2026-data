#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n[N];
char a[N];
int t;
/*string s;
int solve(string q){
	int ans=0;
	int l=0,r=q.size()-1;
	while(l<r){
		if(q[l]!=q[r]) ans++;
		l++;r--;
	}
	return ans;
}*/
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>a[i];
	}
	int x=1,y=0;
	for(x=1;x<=t;x++){
		for(int i=1;i<=n[x];i++){
			s+=a[x];
			y+=1;
		}
	}
	cout<<solve(s);*/
	long long ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>a[i];
	}
	int l=1,r=t;
	while(l<r){
		if(n[l]==n[r]){
			if(a[l]==a[r]){
				l++;r--;
				
			}else{
				ans+=n[l];
			}
			continue;
		}else if(n[l]<n[r]){
			n[r]-=n[l];
			ans+=n[l];
			l++;
		}
		else if(n[l]>n[r]){
			n[l]-=n[r];
			ans+=n[r];
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}