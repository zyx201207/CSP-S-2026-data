#include<bits/stdc++.h> 
using namespace std;
long long a[1000005];
int check(int x,int y){
	int p=x;
	for(int i=x;i<=y;i++){
		if(a[i]==a[i+1]){
			p+=1;
		}
		else{
			return p;
		}
	}
	
}




int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,ans,limit=1,t,d;	
	cin>>n>>m;
	for(int i=1;i<=n;i++){		
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	
		for(int i=1;i<=n;i++){
			sum+=a[i-1];
			if(i>1){
			ans=a[i]*(i-1)-sum ;						
			}
		
		
		if(ans==m){
				t=i;				
				d=check(t,n);
				limit=0;
				break;
				
			}
		else if(ans>m){
			d=i-1;
		limit=0;
			break;
		
		}
		
		
		}		
	
	
	cout<<d;
	
	return 0;
}
