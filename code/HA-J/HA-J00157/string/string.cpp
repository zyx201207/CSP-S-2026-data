#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ed[N],ans=0;
char c[N];
bool lsame=1;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(i!=0&&c[i]!=c[i-1])lsame=0;
		if(i==0){
			ed[i]=a[i];
		}else{
			ed[i]=a[i]+ed[i-1];
		}
	}
	if(n==1){
		cout<<0<<"\n";
		return 0; 
	}else if(n==2){
		if(c[0]==c[1])cout<<0<<"\n";
		else cout<<min(a[0],a[1])<<"\n";
		return 0;
	}
	if(lsame){
		cout<<0<<"\n";
		return 0;
	}
	long long mid=(ed[n-1]+1)/2;
	int l=0,r=n-1,m;
	int pos=0;
	while(l<=r){
		m=(l+r)/2;
		if(ed[m]==mid){
			pos=m;
			break;
		}else if(ed[m]<mid){
			l=m+1;
		}else if(ed[m]>mid){
			if(m==0){
				pos=m;
				break;
			}else if(ed[m-1]<mid){
				pos=m;
				break;
			}else{
				r=m-1;
			}
		}
	}
	if(ed[n-1]%2==0){
		if(ed[pos+1]-ed[pos]==1){
			if(c[pos+1]!=c[pos]){
				ans++;
				a[pos]-=2;
			}
		}
	}
	if(a[pos]==0)pos++;
	int now=pos-1;
	for(int i=pos;i<n;i++){
		while(a[i]>0){
			if(c[i]!=c[now]){
				if(a[i]>=a[now]){
					a[i]-=a[now];
					ans+=a[now];
					now--;
				}else{
					ans+=a[i];
					a[now]-=a[i];
					a[i]=0;
				}
			}else{
				now--;
				if(a[i]>=a[now]){
					a[i]-=a[now];
					now--;
				}else{
					a[now]-=a[i];
					a[i]=0;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
