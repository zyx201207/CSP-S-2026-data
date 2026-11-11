#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],c[30][200010],ans=0,flag=0,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=0;
		while(a[i]){
			b++;
			if(a[i]&1){
				c[b][0]++;
				c[b][c[b][0]]=i;
			}
			a[i]>>=1;
		}
	}
	for(int i=30;i>=1;i--){
		ans<<=1;
		if(c[i][0]>=m&&flag==0){
			ans+=1;
			flag=1;
			t=i;
		}else if(c[i][0]>=m){
			int fl=0;
			for(int j=1;j<=c[i][0];j++){
				for(int k=1;k<=c[t][0];k++){
					if(c[t][k]==c[i][j]){
						fl++;
					}
					if(fl==2){
						ans+=1;
						break;
					}
				}
				if(fl==2){
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
