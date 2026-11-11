#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[500005],tmp;
char c[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		//cout<<a[i]<<' '<<a[j]<<' '<<c[i]<<' '<<c[j]<<endl;
		tmp=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=tmp;
		}
		a[i]-=tmp;a[j]-=tmp;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
