#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,l[2000086],ans=0;
bool z;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=0;i<n;i++) cin>>l[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(j-i==2&&l[j]-l[i]<=d) ans++;
				else{
				for(int k=i+1;k<j;k++){
					if(l[k+1]-l[k-1]<=d&&l[k+1]-l[k]<=d&&l[k]-l[k-1]<=d&&l[k+2]-l[k]<d&&k+2<j) break;
					else z=1;
				}
				if(z){
					for(int k=i+1;k<j;k++){
					if(l[k+1]-l[k-1]<=d&&l[k+1]-l[k]<=d&&l[k]-l[k-1]<=d&&(l[k+2]-l[k]>d&&k+2<j)) {
					z=1;
					break;
					}
					else z=0;
				}
				if(z) ans++;
				}
			}}
		}
		cout<<ans-1;
	}
	return 0;
}
