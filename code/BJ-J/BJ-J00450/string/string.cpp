#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
char c[200005];
long long a[200005];

long long ddp(int l,int r,long long ans){
	if(l>=r)return ans;
	if(a[l]>a[r]){
		if(c[l]!=c[r])ans+=a[r];
		a[l]-=a[r];
		return ddp(l,r-1,ans);
	}
	else if(a[l]<a[r]){
		if(c[l]!=c[r])ans+=a[l];
		a[r]-=a[l];
		return ddp(l+1,r,ans);
	}
	else{//a[l]==a[r];
		if(c[l]!=c[r])ans+=a[l];
		return ddp(l+1,r-1,ans);
	}
}
int cnt=0;
int yb;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cnt+=a[i];
	}
	//yb=cnt/2;
	cout<<ddp(1,n,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
