#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N],sum[N],a1[N];
int n,m,flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		s[i]=0;
		sum[i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++) a[i]=a1[i];
		for(int i=k;i<=n;i++){
			s[a[i]]++;
			if(s[a[i]]>1){
				for(int j=1;j<i;j++){
					if(a[j]==a[i]) flag=1;
					if(flag==1){
						j++;
						a[j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=0) sum[a[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
