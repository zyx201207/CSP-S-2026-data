#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[200005],maxn,p,q;
bool vis[200005];
void f(int x,int y,int last){
	if(x==k){
		maxn=max(maxn,y);
		return;
	}
	for(int i=last;i<=n;i++){
		vis[last]=1;
		f(x+1,y&a[last],last+1);
		vis[last]=0;
		f(x,y,last+1);
		return;
	}
}
bool sq(int x){
	x+=1;
	for(int i=1;i<=30;i++){
		if(x==pow(2,i)){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool flag=1;
	cin>>n>>k;
	q=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=max(p,a[i]);
		q=q&a[i];
		if(!sq(a[i])){
			flag=0;
		}
	}
	if(n<=20){
		f(0,pow(2,30)-1,1);
		cout<<maxn;
	}else if(k==1){
		cout<<p;
	}else if(k==n){
		cout<<q;
	}else if(k==2){
		int oi=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				oi=max(oi,a[i]&a[j]);
			}
		}
		cout<<oi;
	}else if(p<4){
		int one=0,two=0,three=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) one++;
			if(a[i]==2) two++;
			if(a[i]==3) three++;
		}
		if(three>=k){
			cout<<3;
		}else if(three+two>=k){
			cout<<2;
		}else{
			cout<<1;
		}
	}else if(flag){
		sort(a+1,a+1+n,greater<int>());
		cout<<a[k];
	}else{
		sort(a+1,a+1+n,greater<int>());
		int sp=a[1];
		for(int i=1;i<=k;i++){
			sp&=a[i];
		}
		cout<<sp;
	}
	return 0;
} 
