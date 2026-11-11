#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[1000005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,m=n;
	long long x=a[l],y=a[m];
	char p=b[l],q=b[m];
	for(int i=1;;i++){
		if(x>y){
			x-=y;
			if(p==q){
				ans=ans;
			}
			else{
				ans+=y;
			}
			m--;
			y=a[m];
			q=b[m];
		}
		else if(x<y){
			y-=x;
			if(p==q){
				ans=ans;
			}
			else{
				ans+=x;
			}
			l++;
			x=a[l];
			p=b[l];
		}
		else{
			if(p==q){
				ans=ans;
			}
			else{
				ans+=x;
			}
			l++;
			m--;
			x=a[l],y=a[m];
			p=b[l],q=b[m];
		}
		if(m<=l){
			  cout<<ans;
              return 0;
	    }
	}
}
