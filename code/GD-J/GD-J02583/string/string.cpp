#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,nn,m,ans,num[200005];
char a,last,ch[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&m);
		cin>>a;
		if(last==a){
			num[nn]+=m;
		}else{
			nn++;
			num[nn]=m;
			ch[nn]=a;
		}
		last=a;
	}
	int l=1,r=nn; 
	while(l<=r){
		if(num[l]==num[r]&&ch[l]==ch[r]){
			if(l==r) break;
			l++,r--;
			continue;
		}
		if(num[l]!=num[r]&&ch[l]==ch[r]){
			if(num[l]<num[r]){
				num[r]-=num[l];
				l++;
			}else if(num[l]>num[r]){
				num[l]-=num[r];
				r--;
			}
		}else if(num[l]==num[r]&&ch[l]!=ch[r]){
			ans+=num[l];
			l++,r--;
		}else if(num[l]!=num[r]&&ch[l]!=ch[r]){
			if(num[l]>num[r]){
				ans+=num[r];
				num[l]-=num[r];
				r--;
			}else if(num[l]<num[r]){
				ans+=num[l];
				num[r]-=num[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
