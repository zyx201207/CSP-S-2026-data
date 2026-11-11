#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d %c",a+i,c+i);
	int l=1,r=n;
	while(l<r){
		bool f=(a[l]>a[r]);
		if(c[l]!=c[r])ans+=f?a[r]:a[l];
		a[l]-=(f?a[r]:a[l]);
		a[r]-=(f?a[r]:a[l]);
		f?r--:l++;
	}
	cout<<ans;
	return 0;
}
