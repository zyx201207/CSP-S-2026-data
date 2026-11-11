#include<bits/stdc++.h>
#define int1 long long
using namespace std;
int1 n,m,sum,a[500009],fc[500009];
int1 ef(int1 d){
	int1 l=1,r=d,ans=1;
	while(l<=r){
		int1 mid=(l+r)/2;
		int1 w=fc[d]-((a[d]-a[mid])*(mid-1)+fc[mid]);
		if(w>m)l=mid+1;
		else ans=d-mid+1,r=mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int1 i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int1 ans=0;
	for(int1 i=1;i<=n;i++){
		fc[i]=fc[i-1]+(a[i]-a[i-1])*(i-1);
		//cout<<a[i]<<' '<<fc[i]<<' ';cout<<ef(i)<<' '<<i<<' ';
		//if(ef(i)>ans)cout<<'!'<<' '<<m;
		ans=max(ans,ef(i));
		//cout<<'\n';
	}
	cout<<ans;
	return 0;
}
/*#include<bits/stdc++.h>
#define int1 long long
using namespace std;
int1 n,m, a[500009];
int main(){
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int1 dx=a[1],ans=1;
	for(int i=2;i<=n;i++){
		int1 w=a[i]-dx;
		//cout<<w<<'\n';
		if(m<w*(i-1))break;
		dx=a[i];
		ans=i;
		m-=w*(i-1);
	}
	cout<<ans;
	return 0;
}*/
