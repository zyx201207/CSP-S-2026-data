#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
struct now{
	long long a;
	char c;
} nl,nr;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(nl.a==0&&nr.a==0){
			if(c[l]!=c[r])
				ans+=min(a[r],a[l]);
			if(a[l]>a[r]){
				nl.a=a[l]-a[r];
				r--;
			}
			else if(a[r]>a[l]){
				nr.a=a[r]-a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
        }
        else{
        	if(nl.a!=0){
	    		if(c[l]!=c[r])
					ans+=min(a[r],nl.a);
				if(nl.a>a[r]){
					nl.a=nl.a-a[r];
					r--;
				}
				else if(a[r]>nl.a){
					nr.a=a[r]-nl.a;
					nl.a=0;
					l++;
				}
				else{
					nl.a=0;
					r--;
					l++;
				}
			}
			else{
				if(c[l]!=c[r])
					ans+=min(nr.a,a[l]);
				if(a[l]>nr.a){
					nl.a=a[l]-nr.a;
					nr.a=0;
					r--;
				}
				else if(nr.a>a[l]){
					nr.a=nr.a-a[l];
					l++;
				}
				else{ 
					nr.a=0;
					l++;
					r--;
				}
			}
		}
//		cout<<ans<<endl;
	}cout<<ans;
}
