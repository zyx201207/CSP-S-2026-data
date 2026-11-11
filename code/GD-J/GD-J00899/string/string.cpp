#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],cnt+=a[i];
	long long l=0,r=0,ans=0;
	int i=1,j=n;
	while(i<j){
		
		if(l>0&&r>0){
			
			if(l==r){
				if(c[i]!=c[j]){
					ans+=r;
				}
				i++;
				j--;
				l=0;
				r=0;
			}else if(l>r){
				if(c[i]!=c[j]){
					ans+=r;
				}
				
				l=l-r;
				r=0;
				j--;
			}else if(l<r){
				if(c[i]!=c[j]){
					ans+=l;
				}
				
				r=r-l;
				l=0;
				i++;
			}
		}else if(l){
			if(l==a[j]){
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				i++;
				j--;
				l=0;
			}else if(l>a[j]){
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				l=l-a[j];
				j--;
			}else if(l<a[j]){
				if(c[i]!=c[j]){
					ans+=l;
				}
				r=a[j]-l;
				l=0;
				i++;
			}	
		}else if(r){
			if(a[i]==r){
				if(c[i]!=c[j]){
					ans+=r;
				}
				i++;
				j--;
				r=0;
			}else if(a[i]>r){
				if(c[i]!=c[j]){
					ans+=r;
				}
				
				l=a[i]-r;
				r=0;
				j--;
			}else if(a[i]<r){
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				r=r-a[i];
				i++;
			}
		}else{
			if(a[i]==a[j]){
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				i++;
				j--;
			}else if(a[i]>a[j]){
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				l=a[i]-a[j];
				j--;
			}else if(a[i]<a[j]){
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				r=a[j]-a[i];
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
