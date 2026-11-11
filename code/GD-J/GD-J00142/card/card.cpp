#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f3f;
ll n,m,a[N],b[N],tot,ans[N],last[N],suf[N];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]<a[i-1]){
				flag=0;
			}
		}
	} 
	if(flag){
		for(int i=n;i>=1;i--){
			if(suf[a[i]]==0){
				suf[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<suf[i]<<" ";
		}
		exit(0);
	}
	if(n>5000&&m==2){
		ll st1=0,ed1=0,st2=0,ed2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				st1=i;
			}else{
				st2=i;
			}
			if(st1>0&&st2>0){
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]==1){
				ed1=i;
			}else{
				ed2=i;
			}
			if(ed1>0&&ed2>0){
				break;
			}
		}
		if(a[n]==1){
			ans[1]+=n;
			if(st2>st1){
				cout<<ans[1]<<" "<<0;
				exit(0);
			}else{
				ll cnt=1;
				for(int i=st2+1;i<st1;i++){
					if(a[i]==2&&a[i-1]==2){
						cnt++;
					}
				}
				cout<<ans[1]<<" "<<cnt;
				exit(0);
			}
		}
		else if(a[n]==2){
			ans[2]+=n;
			if(st1>st2){
				cout<<0<<" "<<ans[2];
				exit(0); 
			}else{
				ll cnt=1;
				for(int i=st1+1;i<st2;i++){
					if(a[i]==1&&a[i-1]==1){
						cnt++;
					}
				}
				cout<<cnt<<" "<<ans[2];
				exit(0);
			}
		}
	}
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=1;j<=m;j++){
			last[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(last[a[j]]==0){
				b[++tot]=a[j];
//				if(i==2)cout<<tot<<endl;
				last[a[j]]=tot;
			}else{
				for(int k=last[a[j]]+1;k<=tot;k++){
					last[b[k]]=0;
				}
//				if(i==2)cout<<"last"<<a[j]<<":"<<last[a[j]]<<endl;
				tot=last[a[j]]-1;
				b[++tot]=a[j];
				last[a[j]]=tot;
			}
//			if(i==2){
//				cout<<"tot="<<tot<<endl; 
//				for(int k=1;k<=tot;k++){
//					cout<<b[k]<<" ";
//				}
//				cout<<endl;
//			}
		}
//		cout<<tot<<endl;
		for(int j=1;j<=tot;j++){
			ans[b[j]]++;
//			cout<<b[j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}

