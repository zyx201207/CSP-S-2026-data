#include<bits/stdc++.h>
using namespace std;
long long a[200005],c[200005]; 
int b[200005][35]; 
int s[35]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],ans=0;
		while(t){
			ans++;
			b[i][ans]=t%2;
			if(t%2==1){
				s[ans]++;
			}
			t/=2;
		}
	}
	int k=-1;
	for(int i=31;i>=1;i--){
		if(s[i]>=m){
			k=i;
			break;
		}
	}
	if(k==-1){
		cout<<0;
	}
	else{
		int aa=0;
	    for(int i=1;i<=n;i++){
	    	if(b[i][k]==1){
	    		aa++;
	    		long long s=0,kk=1;
	    		for(int j=1;j<=k;j++){
	    			s+=b[i][j]*kk;
	    			kk*=2;
				}
				c[aa]=s;
			}
		}
		sort(c,c+aa+1);
		long long ans=c[aa];
		for(int i=aa-1;i>=aa-m+1;i--){
			ans&=c[i];
		}	
		cout<<ans;
	}
	return 0;
} 
