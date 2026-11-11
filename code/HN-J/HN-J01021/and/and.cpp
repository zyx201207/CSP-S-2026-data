#include<bits/stdc++.h>
using namespace std;
//#define int long long
int x[200010];
bool cmp(int n,int m){
	return n>m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	//cout<<"n="<<n<<",m="<<m<<"\n\n";
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1,cmp);
	int len=n;
	int ans=0;
	int i=1;
	for(int o=1;o<=30;o++)i*=2;
	for(;i>=1;i/=2){
		//cout<<i<<":\n";
		int tot=0;
		for(int j=1;j<=len;j++){
			if((x[j]&i)>0){
				tot++;
			}
			//cout<<tot<<"\n";
		}
		//cout<<"tot="<<tot<<"\n";
		if(tot>=m){
			ans+=i;
			int k=0;
			for(int j=1;j<=len;j++){
				if((x[j]&i)>0){
					x[++k]=x[j];
				}
			}
			len=k;
		}
	}
	cout<<ans;
	return 0;
} 
