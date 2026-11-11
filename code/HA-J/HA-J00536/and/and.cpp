#include<bits/stdc++.h>
using namespace std;
long long a[200009],n,m,l,ma;
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>m;
   
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
	a[0]=a[n];
	for(int i=1;i<=n;i++){
	long long b[200009]={0};
	
	string s="";
		for(int j=i;j<=i+m-1;j++){
			long long k=a[j%n];
			l=0;
			while(k){
				b[l]+=k%2;
				
				k/=2;
				l++;
				
			}
			
		}
		
		for(int j=l-1;j>=0;j--){
			if(b[j]==m)s+='1';
			else s+='0';
		}
		long long k=0,c=1;
		
		
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='1')k+=c;
			c*=2;
		}
		ma=max(ma,k);
	}
	cout<<ma;
	return 0;
	
}
