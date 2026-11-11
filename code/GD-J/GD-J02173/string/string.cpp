#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001],sum[200001];
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int L=sum[n]/2,bj1=0,bj2=0;
	for(int i=1;i<=n;i++){
		if(sum[i]>=L){
			bj1=i;
			bj2=i;
			break;
		}
	}
	int ans=0,l1=L,r1=L;
	for(int k=1;l1>=1&&r1<=sum[n];++k){
		int l=l1-sum[bj1-1],r=sum[bj2]-r1;
		if(r1==sum[n]){
			for(int i=1;i<=bj1-1;i++) ans+=a[i];
			break;
		}
		if(l1==0){
			for(int i=bj2+1;i<=n;i++) ans+=a[i];
			break;
		} 
		if(l>=r){
			int p=l-r;
//			cout<<l<<' '<<r<<" "<<l1<<" "<<r1<<"\n";
			if(p==0){
				if(a[bj1-1]<=a[bj2+1]) r1+=a[--bj1],l1-=a[bj1],ans+=a[bj1];
				else r1+=a[++bj2],l1-=a[bj2],ans+=a[bj2];
			}
			while(p){
				if(a[bj2+1]<=p&&c[bj2+1]!=c[bj2]){
					ans+=a[++bj2];
					p-=a[bj2],r1+=a[bj2];
					++bj2;
				}
				else if(a[bj2+1]>p&&c[bj2+1]!=c[bj2]){
					ans+=a[++bj2];
					r1+=p,p=0;
				}
				else if(a[bj2+1]<=p&&c[bj2+1]==c[bj2]){
					p-=a[++bj2];
					r1+=a[bj2];
					++bj2;
				}
				else if(a[bj2+1]>p&&c[bj2+1]==c[bj2]){
					r1+=p,p=0;
					++bj2;
				}
			}
		}
		else{
			int p=r-l;
//			cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<"\n";
			if(p==0){
				if(a[bj1-1]<=a[bj2+1]) r1+=a[--bj1],l1-=a[bj1],ans+=a[bj1];
				else r1+=a[++bj2],l1-=a[bj2],ans+=a[bj2];
			}
			while(p){
				if(a[bj1-1]<=p&&c[bj1-1]!=c[bj1]){
					ans+=a[--bj1];
					p-=a[bj1],l1-=a[bj1];
					--bj1;
				}
				else if(a[bj1-1]>p&&c[bj1-1]!=c[bj1]){
					ans+=a[--bj1];
					l1-=p,p=0;
				}
				else if(a[bj1-1]<=p&&c[bj1-1]==c[bj1]){
					p-=a[--bj1];
					l-=a[bj1];
					--bj1;
				}
				else if(a[bj1-1]>p&&c[bj1-1]==c[bj1]){
					l1-=p,p=0;
					--bj1;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
/*
 l,r是长度
 l1,r1为边界 
*/
