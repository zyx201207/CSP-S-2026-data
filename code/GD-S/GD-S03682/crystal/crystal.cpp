#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c,l,f=1,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(f)c=a[i]-l,f=0;
		if(c&&c!=a[i]-l)c=0;
		l=a[i];
	}
	if(c){
		cout<<(-1+int(sqrt(m/c*8+1)))/2+1;
	}
	else{
		sort(a,a+n);
		for(int i=0;i<n;i++){
			int p=i-1,k=m,cnt=1;
			while(p>=0&&k>=(a[i]-a[p])){
				k=k-(a[i]-a[p]);
				cnt++;
				p--;
			}
			ans=max(cnt,ans);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
