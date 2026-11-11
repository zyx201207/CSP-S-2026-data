#include <bits/stdc++.h>
using namespace std;
int n,rp;
char c[214514],h[214514];
long long a[214514],b[214514],s,ans1,ans2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		b[i]=a[i];
		h[i]=c[i];
	}
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>n/2;j--){
			if(a[i]<=a[j]){
				if(c[i]!=c[j])ans1+=a[i];
				a[j]-=a[i];
				a[i]=b[i]-a[i];
				break;
			}else{
				a[i]-=a[j];
				if(c[i]!=c[j])ans1+=a[j]; 
				c[j]=c[i];
			}
		}
	}
	int m;
	rp=114514;
	if(n%2==0)m=n/2;
	else m=n/2+1;
	for(int i=n;i>m;i--){
		for(int j=1;j<=m;j++){
			if(a[i]<=a[j]){
				if(c[i]!=c[j])ans1+=a[i];
				a[j]-=a[i];
				a[i]=b[i]-a[i];
				break;
			}else{
				a[i]-=a[j];
				if(c[i]!=c[j])ans1+=a[j]; 
				c[j]=c[i];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		a[i]=b[i];
		c[i]=h[i];
	}
	
	rp=114514;
	if(n%2==0)m=n/2;
	else m=n/2+1;
	for(int i=n;i>m;i--){
		for(int j=1;j<=m;j++){
			if(a[i]<=a[j]){
				if(c[i]!=c[j])ans2+=a[i];
				a[j]-=a[i];
				a[i]=b[i]-a[i];
				break;
			}else{
				a[i]-=a[j];
				if(c[i]!=c[j])ans2+=a[j]; 
				c[j]=c[i];
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>n/2;j--){
			if(a[i]<=a[j]){
				if(c[i]!=c[j])ans2+=a[i];
				a[j]-=a[i];
				a[i]=b[i]-a[i];
				break;
			}else{
				a[i]-=a[j];
				if(c[i]!=c[j])ans2+=a[j]; 
				c[j]=c[i];
			}
		}
	}
	cout << min(ans1,ans2);
	return 0;
}
