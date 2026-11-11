#include<bits/stdc++.h>
using namespace std;
struct sd{
	long long m;
	char s;
};
sd a[200005];long long ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
int n;
cin>>n;	
for(int i=0;i<n;i++){
	cin>>a[i].m >>a[i].s ;
}	
	for(int i=0,j=n-1;j>i;){
		if(a[i].s!=a[j].s ){
			if(a[i].m>=a[j].m ){
		
			a[i].m -=a[j].m ;
			ans+=a[j].m ;	j--;
			}else{
			
			a[j].m -=a[i].m ;
			ans+=a[i].m ;	i++;
			}
		}else{
			if(a[i].m>=a[j].m ){
			
			a[i].m -=a[j].m ;j--;
			}else{
			
			a[j].m -=a[i].m ;	i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
