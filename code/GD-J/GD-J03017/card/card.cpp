#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],s[N],tmp,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%lld",&a[i]);
		bool f=false;
		for(int j=1;j<=tmp;j++){
			if(f){
				s[j]=0;
				continue;
			}
			if(s[j]==a[i]){
				f=1;
				tmp=j;
			} 
		}
		if(!f) s[++tmp]=a[i];
	}
	for(int i=1;i<=tmp;i++){
		ans[s[i]]++;
//		cout<<1<<' '<<s[i]<<' '<<ans[s[i]]<<endl;
	}//µÚÒ»ÂÖ 
	for(int i=2;i<=n;i++){
		memset(s,0,sizeof(s));
		tmp=0;
		for(int k=i;k<=n;k++){//i=k
			bool f=false;
			for(int j=1;j<=tmp;j++){
				if(f){
					s[j]=0;
					continue;
				}
				if(s[j]==a[k]){
					f=1;
					tmp=j;
				} 
			}
			if(!f) s[++tmp]=a[k];
		}
		for(int j=1;j<=tmp;j++){
			ans[s[j]]++;
//			cout<<i<<' '<<s[j]<<' '<<ans[s[j]]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
