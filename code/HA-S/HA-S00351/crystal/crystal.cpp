#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,flag;
long long en[N];
long long f[N],t[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>en[i];
	}
	sort(en+1,en+1+n);
	if(en[1]<0){
		flag=1;
		int jia=0-en[1]+1;
		for(int i=1;i<=n;i++){
			en[i]+=jia;
		}
	}
	f[0]=en[1];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(en[i]-en[i-1]);
		t[f[i]]=1;
	}
	f[0]=0;
	for(int i=0;i<=n;i++){
		if(t[f[i]+m]){
			for(int j=i;j<=n;j++){
				if(f[j]-m==f[i]){
					if(i==0){
						ans=max(ans,(j-i));
					}
					else{
						ans=max(ans,(j-i+1));
					}
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
