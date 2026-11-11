#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g,n,m[100000],k[100000],l[100000],sum=0,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>k[i];
		ans=max(ans,k[i]);
	}
	for(int i=1;i<=a;i++){
	sum=0;
		for(int j=i;j<=a;j++){
			sum=j-1;
			if(l[k[j]]==0){
				l[k[j]]++;
			}else{
				while(k[sum]!=k[j]){
					l[k[sum]]=0;
					sum--;
				}
				l[k[j]]=0;
				l[k[j]]++;
			}
		}
		for(int j=1;j<=a;j++){
			if(l[k[j]]==1){
				m[k[j]]++;
				l[k[j]]=0;
			}
		}
	}
	for(int j=1;j<=a;j++){
		if(m[j]>0){
			cout<<m[j]<<' ';
		}
	}
		fclose(stdin);
    fclose(stdout);
	return 0;
}
