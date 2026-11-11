//GZ-J00204 ∫Î“„÷–—ß —Ó •Ω‹ 
#include<bits/stdc++.h>
using namespace std; 
int n,m,a[300000]={0},k,cnt=0,b[300000]={0},ans[300000]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k;
		b[i]=k;
		if(i==0){
			a[0]=k;
			cnt++;
		}
		else{
			for(int j=0;j<=cnt-1;j++){
				if(k==a[j]){
					for(int _=j+1;_<=cnt-1;_++){
						a[_]=0;
						cnt--;
					}
					break;
				}
				if(j==(cnt-1)&&k!=a[j]){
				
					a[cnt]=k;
					cnt++;
				}
			}
		}
	}
	for(int j1=0;j1<n;j1++){
		for(int j2=1;j2<=m;j2++){
			if(a[j1]==j2){
				ans[j2]++;
			
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int h=1;h<n;h++) a[h]=0;
		a[0]=b[i];
		cnt=1;
		for(int k1=i+1;k1<n;k1++){
			for(int j=0;j<=cnt-1;j++){
				if(b[k1]==a[j]){
					for(int _=j+1;_<=cnt-1;_++){
						a[_]=0;
						cnt--;
					}
					break;
				}
				if(j==(cnt-1)&&b[k1]!=a[j]){
					
					a[cnt]=b[k1];
					cnt++;
				}
			}
		}
		for(int s=0;s<n;s++) cout<<a[s];
		cout<<endl;
		for(int j1=0;j1<n;j1++){
			for(int j2=1;j2<=m;j2++){
				if(a[j1]==j2){
					ans[j2]++;
					
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i]!=0) cout<<ans[i]<<" ";
	}
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
//4 3 1 2 1 3
