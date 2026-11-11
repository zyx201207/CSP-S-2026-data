#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],lastappear[N],sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
	
		//for(int i=1;i<=n;i++)
		for(int i=1;i<=n;i++){
			//cout<<"now i="<<i<<'\n';
			int ans[N],xb=0,start=1;
			for(int j=1;j<=n;j++){
				ans[j]=0;
				lastappear[j]=0;
			}
			for(int j=i;j<=n;j++){
				if(lastappear[a[j]]==0||lastappear[a[j]]>xb){
					xb++;
					lastappear[a[j]]=xb;
					
					ans[xb]=a[j];
				}else{
					//cout<<"pd! lastappear[a[j]]="<<lastappear[a[j]]<<" a[j]:"<<a[j]<<" xb:"<<xb<<'\n';
					xb=lastappear[a[j]];
					//lastappear[a[j]]=j;
					//xb++;
					//ans[xb]=a[j];
				}
				
			}for(int j=start;j<=xb;j++){
				sum[ans[j]]++;
				
			}/*
			cout<<"xb:"<<xb<<'\n';
			
			for(int j=1;j<=xb;j++){
				cout<<ans[j]<<" ";
			}
			cout<<'\n';
			*/
			
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}

	}else if(m==2){
		int a1=0,a2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[n]==1){
				a1++;
			}else if(a[i]==2&&a[n]==2){
				a2++;
			}else if(a[i]==1&&a[n]==2){
				a1++;
				a2++;
			}else if(a[i]==2&&a[n]==1){
				a1++;
				a2++;
			}
		}cout<<a1<<" "<<a2;
	}
	else{
		for(int i=1;i<=n;i++){
			//cout<<"now i="<<i<<'\n';
			int ans[N],xb=0,start=1;
			for(int j=1;j<=n;j++){
				ans[j]=0;
				lastappear[j]=0;
			}
			for(int j=i;j<=n;j++){
				if(lastappear[a[j]]==0||lastappear[a[j]]>xb){
					xb++;
					lastappear[a[j]]=xb;
					
					ans[xb]=a[j];
				}else{
					//cout<<"pd! lastappear[a[j]]="<<lastappear[a[j]]<<" a[j]:"<<a[j]<<" xb:"<<xb<<'\n';
					xb=lastappear[a[j]];
					//lastappear[a[j]]=j;
					//xb++;
					//ans[xb]=a[j];
				}
				
			}for(int j=start;j<=xb;j++){
				sum[ans[j]]++;
				
			}/*
			cout<<"xb:"<<xb<<'\n';
			
			for(int j=1;j<=xb;j++){
				cout<<ans[j]<<" ";
			}
			cout<<'\n';
			*/
			
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
