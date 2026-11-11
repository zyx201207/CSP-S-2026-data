#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll inf=2e18+1;
ll cas,t,n,d,a[N],ans=0;
ll s[N],sec_far[N],top=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cas>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			top=0;
			ll min_adjust=inf,sec_adjust=inf,id=0;
			s[++top]=i;
			while(1){
				if(s[top]==n) break;
				ll j=upper_bound(a+1,a+n+1,a[s[top]]+d)-a-1;
				if(j<=s[top]) break;
				s[++top]=j;
				if(j-1>s[top-1]) sec_far[top]=j-1;
				else sec_far[top]=0;
//				cout<<min_adjust<<" "<<sec_adjust<<" "<<id<<"\n";
				if(sec_far[top-1]){
					if(a[j]-a[sec_far[top-1]]<min_adjust){
						sec_adjust=min_adjust;
						min_adjust=a[j]-a[sec_far[top-1]];
						id=top-1;
						if(s[top-1]-s[top-2]>=3&&a[j]-a[s[top-1]-2]<sec_adjust) sec_adjust=a[j]-a[s[top-1]-2];
					}
					else if(a[j]-a[sec_far[top-1]]<sec_adjust) sec_adjust=a[j]-a[sec_far[top-1]];
				}
				if(min_adjust<=d){
					bool flag=0;
					if(sec_adjust<=d) flag=1;
					if(id>1&&sec_far[id-1]&&a[sec_far[id]]-a[sec_far[id-1]]<=d) flag=1;
					if(flag) continue;
					if(sec_far[top-1]){
						if(id!=top-1){
							ll p=upper_bound(a+1,a+n+1,a[sec_far[top-1]]+d)-a;
							ans+=j-p+1;
//							cout<<"type1 "<<j-p+1<<"\n";
						}
						else{
							ll q=0;
							if(s[top-1]-s[top-2]>=3) q=upper_bound(a+1,a+n+1,a[s[top-1]-2]+d)-a;
							else q=s[top-1]+1;
							ans+=j-q+1;
//							cout<<"type2 "<<j-q+1<<"\n";
						}
					}
					else{
						ans+=j-s[top-1];
//						cout<<"type3 "<<j-s[top-1]<<"\n";
					}
				}
				else{
					if(!sec_far[top-1]){
//						cout<<"type4 0\n";
						continue;
					}
					ll p=upper_bound(a+1,a+n+1,a[sec_far[top-1]]+d)-a-1;
					if(sec_far[top-2]&&a[p]-a[sec_far[top-2]]<=d) continue;
					ll q=0;
					if(s[top-1]-s[top-2]>=3) q=upper_bound(a+1,a+n+1,a[s[top-1]-2]+d)-a;
					else q=s[top-1]+1;
					ans+=p-q+1;
//					cout<<"type5 "<<p-q+1<<"\n";
				}
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
