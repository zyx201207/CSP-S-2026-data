#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
long long ans,lf,rt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(!lf) lf=a[l];
		if(!rt) rt=a[r];
		if(lf>=rt){
			if(c[l]!=c[r])ans+=rt;
			lf-=rt;
			rt=0;
		}else{
			if(c[l]!=c[r])ans+=lf;
			rt-=lf;
			lf=0;
		}
		if(!lf) l++;
		if(!rt) r--;
	}
	cout<<ans;
	return 0;
}


