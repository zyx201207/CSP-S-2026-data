#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],v[200005],MAX,MIN=LLONG_MAX,sum=(1<<30)-1,s[200005];
void DFS(int x,int sum){
	if(x>m){
		MAX=max(MAX,sum);
		return;
	}for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			DFS(x+1,sum&a[i]);
			v[i]=0;
		}
	}
}bool chk(){
	for(int i=1;i<=n;i++){
		if(log2(a[i]+1)!=(int)log2(a[i]+1)){
			return false;
		}
	}return true;
}int MAXX(){
	int MAX=0;
	for(int i=1;i<=n;i++){
		MAX=max(a[i],MAX);
	}return MAX;
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n<=20){
		DFS(1,sum);
		cout<<MAX;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			MAX=max(MAX,a[i]);
		}cout<<MAX;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			sum&=a[i];
		}cout<<sum;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				MAX=max(MAX,a[i]&a[j]);
			}
		}cout<<MAX;
	}else if(chk()){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}else if(MAXX()<4){
		for(int i=1;i<=n;i++){
			s[a[i]]++;
		}if(m<=s[3]){
			cout<<3;
		}else if(m<=s[3]+s[2]){
			cout<<2;
		}else if(m<=s[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
}
