#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s;
int o[500009],a[500009],di[500009],p[500009];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		p[i]=s;
	}
	for(int l=1;l<=n;l++){
		for(int k=0;k<=3000;k++){
			o[k]=0;
			if(k<l) di[k]=1;
			else di[k]=0;
		}
		for(int i=l;i<=n;i++){
			s=p[i];
			if(o[s]==0) o[s]=i,di[s]=0;
			else{
	//			cout<<o[s]<<" "<<i<<endl;
				for(int j=o[s]+1;j<i;j++){
//					cout<<p[j]<<endl;
					di[p[j]]=1;
					o[p[j]]=0;
				}
				o[s]=i;
			}
		}
	//	cout<<di[2]<<endl;
		for(int i=1;i<=m;i++){
			if(di[i]==0) a[i]++;
//			cout<<a[i]<<" ";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

