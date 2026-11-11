#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2*1e5+5;
int n,m[N],ans1,ans2,sum1,sum2,cnt;
struct xh{
	int nu,ty;
};
stack<xh> st1,st2;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
		ans1+=m[i];
	}
	//cout<<ans<<endl;
	ans1/=2;
	//cout<<ans<<endl;
	ans2=ans1;
	int i=1,j=n;
	while(m[i]<=ans1){
		ans1-=m[i];
		st1.push({m[i],c[i]});
		i++;
	}
	while(m[j]<=ans2){
		ans2-=m[j];
		st2.push({m[j],c[j]});
		j--;
	}
	if(ans1!=0){
		st1.push({ans1,c[i]});
	}
	if(ans2!=0){
		st2.push({ans2,c[j]});
	}
	i=1,j=n;
	while(!st1.empty()){
		xh fr=st1.top();
		st1.pop();
		cnt+=fr.nu;
		while(m[j]<fr.nu){
			if(c[j]!=fr.ty){
				sum1+=m[j];
			}
			fr.nu-=m[j];
			j--;
		}
		m[j]-=fr.nu;
		if(c[j]!=fr.ty){
			sum1+=fr.nu;
		}
		if(m[j]==0){
			j--;
		}
	}
	while(!st2.empty()){
		xh fr=st2.top();
		st2.pop();
		cnt+=fr.nu;
		while(m[i]<fr.nu){
			if(c[i]!=fr.ty){
				sum2+=m[i];
			}
			fr.nu-=m[i];
			i++;
		}
		m[i]-=fr.nu;
		if(c[i]!=fr.ty){
			sum2+=fr.nu;
		}
		if(m[i]==0){
			i++;
		}
	}
	cout<<min(sum1,sum2)<<endl;
	//cout<<cnt;
	return 0;
}
