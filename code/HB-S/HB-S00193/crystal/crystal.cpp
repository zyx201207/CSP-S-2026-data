#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[600005];
int p=1,f=0;
bool gh=1;
void check(long long s){
	long long sum=0,er=0;
	int temp=0;
	bool k=1;
	if(s==a[n]) temp=n;
	else {
		for(int i=1;i<=n;i++){
		if(a[i]>s){
			temp=i-1;
			break;
		}
	}
}
	for(int i=temp;i>0;i--){
		if(sum+(s-a[i])<=m){
			er++;
			sum+=s-a[i];
	
		}
		else 
		{
			k=0;
		break;
	}
		}

		if(sum==0) {
				p=f;

		}
		else if(!k&&temp>(n-temp)/2){
		   f=temp;
		}
		else{
		
			p=temp+1;
			
	
			}
			ans=max(ans,er);
		/*if(er>ans&&sum>=m){
			p=temp+1;
			ans=er;
			}
			else if(er<ans||sum<m){
				f=temp;
			}*/
			
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    f=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    
    long long l=a[1],r=a[n];
    while(p<=f){
		l=a[p];
		r=a[f];
		long long mid=(l+r)/2;
		check(mid);

		
		if(p==f) {
			check(a[p]);
			break;
		}
		
		}
    cout<<ans;
return 0;	
}

