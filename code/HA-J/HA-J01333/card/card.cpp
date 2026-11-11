#include <bits/stdc++.h>
using namespace std;
int a[500005],k[300005],kk,s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int g=1;g<=n;g++){
		kk=0;
		memset(k,0,sizeof(k));
		for(int i=g;i<=n;i++){
			bool r=1;
			int lk=0;
			for(int j=1;j<=kk;j++){
				if(k[j]==a[i]){
					r=0;
					lk=j;
					break;
				}
			}
			if(r){
				kk++;
				k[kk]=a[i];
			}else{
				kk=lk;
				k[kk]=a[i];
			}
		}
		for(int i=1;i<=kk;i++){
			s[k[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}