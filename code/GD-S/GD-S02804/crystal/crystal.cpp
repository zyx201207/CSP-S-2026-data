#include<bits/stdc++.h>
using namespace std;
long long n,m,q[600010],o,p,ma;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		ma=max(ma,q[i]);
	}
	sort(q+1,q+n+1);
	if(n<100000&&ma<1000){
		ma=0;
		for(int i=n;i>=1;i--){
			o=0;p=m;
			if(q[i]==q[i+1]){
				continue;
			}
			for(int j=i;j>=1;j--){
				if(p-q[i]+q[j]>=0){
					p-=q[i]-q[j];
					o+=1;
					if(j==1){
						cout<<max(ma,o);
						return 0;
					}
				}
				else{
					break;
				}
			}
			ma=max(ma,o);
		}
	}
	else{
		long long l=1,r=n;
		ma=0;
		while(l<r){
			o=0;p=m;
			long long mid=(l+r)/2;
			for(int j=mid;j>=1;j--){
				p-=q[mid]-q[j];
				if(p>=0){	
					o+=1;
				}
				else{
					break;
				}
			}
			if(p>0){
				l=mid+1;
				ma=max(ma,o);
			}
			else if(p<0){
				r=mid-1;
			}
			else{
				cout<<max(ma,o);
				return 0;
			}
		}
		cout<<ma;
	}
	
	return 0;
} 
