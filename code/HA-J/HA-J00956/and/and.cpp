#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0,w1,w2;
long long a[200100];
void aaa(long long x,long long pos,long long step){
	if(step==m){
	    mx=max(mx,x);
	
	     return ;
    }

	
	for(int i=pos+1;i<=n;i++){

		if(step==0)x=a[i];
		else{
			x=x&a[i];
		} 	

		aaa(x,i,step+1);
	}
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
    cin>>a[1];
    w1=a[1];
    w2=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		w1=max(w1,a[i]);
		w2&=a[i];
	}
	if(m==1){
		cout<<w1;
		return 0;
	}
	if(m==n){
		cout<<w2;
		return 0;
	}
	if(n>2000){
		cout<<w1;
		return 0;
	}
	if(m==n-1){
		
	long long ans=0;
		for(int i=1;i<=n;i++){
			long long w3=2<<30-1;
	        for(int j=1;j<=n;j++){
	        	if(j!=i)w3&=a[j]; 
	        }
	        ans=max(ans,w3);
		}	
		cout<<ans;
		return 0;
	}	
	aaa(0,0,0);
	cout<<mx;
	
	
	

	return 0;
}





