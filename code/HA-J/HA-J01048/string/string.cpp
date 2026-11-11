#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1e5+5;
int n;
sum[N],ys[N],ysc[N],k;
int a[N],ans;
char c[N];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	ys[++k]=0;
	for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	sum[i]=sum[i-1]+a[i];
	ys[++k]=sum[i];
	ysc[k]=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
		
	}
    for(int i=1;i<=sum[n]/2;i++){
    	if(s[i]!=s[sum[n]-i+1])ans++;
    }

    cout<<ans;
	return 0;
}
