#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum;
int n;
char c[500005];
int a[500005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n,yu1=a[1],yu2=a[n],ans=0; 
	while(i<j){
		if(yu1==yu2){
			if(c[i]!=c[j])ans+=yu1;
			i++;
			j--;
			yu1=a[i];
			yu2=a[j];
		}
		else if(yu1<yu2){
			if(c[i]!=c[j])ans+=yu1;
			i++;
			yu2-=yu1;
			yu1=a[i];
		}
		else{
			if(c[i]!=c[j])ans+=yu2;
			j--;
			yu1-=yu2;
			yu2=a[j];
		}
	}
	cout<<ans; 
	return 0;
}

