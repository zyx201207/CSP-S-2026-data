#include<bits/stdc++.h>
using namespace std;
int qian[2000010],hou[2000010],daoda[2000010];
long long c,t,n,d,l,r,p,q,ans,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		qian[1]=1;
		l=1;
		for(int i=2;i<=n;i++){
			while(l<=i){
				if(a[i]-a[l]>d){
					l++;
				}
				else{
					qian[i]=l;
					break;
				}
			}
		}
		hou[1]=1;
		r=n;
		for(int i=n-1;i>=1;i--){
			while(r>=i){
				if(a[r]-a[i]>d){
					r--;
				}
				else{
					hou[i]=r;
					break;
				}
			}
		}
		daoda[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]<=d){
				daoda[i]=daoda[i-1];
			}
			else{
				daoda[i]=i;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(hou[i]-i==2){
				if(hou[i+1]>i+2){
					p=hou[i+1]-i-2;
					q=min(i,qian[i+1]-1)-daoda[i]+1;
					ans+=p*q;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
