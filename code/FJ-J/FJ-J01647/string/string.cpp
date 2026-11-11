#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b,q2[100007],l=0,z=0;
char q[100007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>q2[i]>>q[i]; 
	for(ll i=1;i<=(n+1)/2;i++){
		if(q2[i]==q2[n-i+1]){
			if(q[i]==q[n-i+1]) continue;
			else z+=q2[i];
		}else{
			if(i==n-i){
				if(q[i]!=q[n-i+1]) z+=min(q2[i],q2[n-i+1]);
				break;
			}
			if(q[i]!=q[n-i+1]) z+=min(q2[i],q2[n-i+1]);
			if(q2[i]>q2[n-i+1]){
				if(q[n-i]!=q[i]) z+=(q2[i]-q2[n-i+1]);
				q2[n-i]-=(q2[i]-q2[n-i+1]);
				q2[n-i+1]=q2[i];
			}else if(q2[i]<q2[n-i+1]){
				if(q[i+1]!=q[n-i+1]) z+=(q2[n-i+1]-q2[i]);
				q2[i+1]-=(q2[n-i+1]-q2[i]);
				q2[i]=q2[n-i+1];
			}
		}
		
	}
	cout<<z<<endl;
	
	return 0;
}

