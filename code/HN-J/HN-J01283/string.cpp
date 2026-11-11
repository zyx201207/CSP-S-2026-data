#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,l=1,r=1;
long long a[N],aa[N],ans;
char c[N],cc[N];
void Make(){
	if(a[l]>aa[r]) a[l]-=aa[r],r++;
	else if(a[l]<aa[r]) aa[r]-=a[l],l++;
	else r++,l++;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++) aa[i]=a[n-i+1],cc[i]=c[n-i+1];
	while(true){
		if(c[l]!=cc[r]){
			ans+=min(aa[r],a[l]);
			Make();
		}else Make();
		if(l>n||r>n) break;
	}
	cout<<ans/2;
	return 0;
} 
