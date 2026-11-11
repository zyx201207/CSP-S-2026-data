#include<bits/stdc++.h>
using namespace std;
long long a[200005],b,n,m,ans;
char c;
int d(int x,int c,long long an){
	if(c==0){
		ans=max(ans,an);
		return 0;
	}
	int an1;
	for(int i=x;i<=n-c+1;i++){
		
		if(x==1){
			an=a[i];
			an1=an;
		}else{
			an1=an;
			an&=a[i];
		}
		d(i+1,c-1,an);
		an=an1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}d(1,m,0);
	cout<<ans;
	return 0;
} 

