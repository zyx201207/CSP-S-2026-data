#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ULL unsigned long long
const int N=2e5+5;
const ULL M=1e9;
int n,a[N],ans;
char t[M],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=0;
	ULL len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r=l+a[i]-1;
		for(ULL j=l;j<=r;j++){
			t[j]=c[i];
		}
		len+=a[i];
		l+=a[i];
	}
	ULL i=1,j=len;
	while(i<=j){
		//cout<<'0';	
		if(t[i]!=t[j])ans++;
		i++,j--;
	} 
	cout<<ans;
	return 0;
}

