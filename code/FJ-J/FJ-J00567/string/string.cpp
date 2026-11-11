#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r;
long long ans,t,sq,b;
char c[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sq+=a[i];
	}if(sq%2==1){
		b=sq/2;
	}else{
		b=sq/2;
	}while(true){
		if(l>=r)break;
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r])ans+=a[r];
			l++;
			r--;
		}
	}cout<<ans;
	return 0;
} 
