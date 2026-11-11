#include<bits/stdc++.h>
#define du double
#define ll long long
using namespace std;
const int M=2e5+5;
/*
aabbc
*/
int la[M],a[M];
ll sum=0,ans=0;
char lx[M],x[M];
string s="";
//aaaabbbbabab
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	int maxx=-1;
	for(int i=1;i<=n;++i){
		cin>>la[i]>>lx[i];
		sum+=la[i];
		maxx=max(maxx,la[i]);
	}
	
	if(maxx<=505){
		for(int i=1;i<=n;++i){
			while(la[i]--){
				s+=lx[i];
			}
		}
		int l=s.size();
		for(int i=0;i<l/2;++i){
			if(s[i]!=s[l-i-1])ans++;
		}
		
	}else{
		ll mid=(sum+1)/2,qian=0;
		int id,dx;
		for(int i=1;i<=n;++i){
			qian+=la[i];
			if(qian>mid){
				id=i;
				dx=mid-(qian-la[i]);
				break;
				}
		a[i]=la[i];
		x[i]=lx[i];
		}
		a[id]=dx;x[id]=lx[id];
		a[id+1]=la[id]-dx;x[id+1]=lx[id];
		for(int i=id+2;i<=n+1;++i){
			a[i]=la[i-1];
			x[i]=lx[i-1];
		}
		ll l=a[1],r=a[n+1];
		int idl=1,idr=n+1;
		ll nx=0;
		while(nx<=mid){
			//1 1 1 2 4
			if(l>r&&nx+l<=mid){
				while(r+a[idr-1]<=l){
					idr--;
					r+=a[idr];
					if(x[idl]!=x[idr]){
						ans+=a[idr];
					}
				}
				if(x[idl]!=x[idr-1]){
					ans+=(l-r);
				}
				nx+=l;
				l=a[++idl];
				r=r+a[--idr]-l;
			}else if(l<r&&nx+r<=mid){//1 1 1 2 4
				while(l+a[idl+1]<=r){
					idl++;
					l+=a[idl];
					if(x[idl]!=x[idr]){
						ans+=a[idl];
					}
				}
				if(x[idl+1]!=x[idr]){
					ans+=(r-l);
				}
				nx+=r;
				r=a[--idr];
				l=l+a[++idl]-r;
			}else if(l==r){//l==r
				nx+=l;
				if(x[idl]!=x[idr])ans+=l;
				l=a[++idl];
				r=a[--idr];
			}
		}
	}
	cout<<ans;
	return 0;
}
