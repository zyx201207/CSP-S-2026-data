#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int c,t,f=0x3f3f3f3f,cnt,flag,ad;
long long d;
void dfs(long long L,long long l,long long r,long long ll,long long a[]){
	if(L==r){
		if(ll<f){
			f=ll;
		    cnt=1;
		}else if(ll==f){
			cnt++;
	    }else{
			ad=1;
			return;
		}
	    if(cnt>=3){
			flag=1;
			return;
		}
	}
	if(l==r){
		if(ll+1<f){
			f=ll+1;
			cnt=1;
		}else if(ll+1==f){
			cnt++;
		}else{
			ad=1;
			return;		
		}
		if(cnt>=3){
		    flag=1;
		    return;
		}
	}
	if(a[l]-a[L]<=d){
		dfs(L,l+1,r,ll,a);
		dfs(L+1,l+1,r,ll+1,a);
		if(flag||ad){
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,a[2000010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long r,l=1;
		while(l<n&&l<r){
			r=l+3;
			while(r<n){
				flag=0;
				ad=0;
				if(d<a[r]-a[l]){
				long long L=a[r]-d,R=a[l]+d;
				if((a[r]-a[l])%d){
					int e=(a[r]-a[l])/d+1;
				}else{
					int e=(a[r]-a[l])/d;
				}
				dfs(a[l],a[l],R,0,a);
				if(flag){
					break;
				}
				flag=0;
				ad=0;
				while(R+d<n){
					dfs(R,R,R+d,0,a);
				    if(flag){
					    break;
				    }
				    flag=0;
				    ad=0;
					R+=d;
				}
				if(flag){
					break;
				}
				flag=0;
				ad=0;
				dfs(L,L,a[r],0,a);
				if(flag){
					break;
				}
				flag=0;
				ad=0;
				cnt++;
			}
			if(flag){
				break;
			}
			r++;
			}
			l++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
