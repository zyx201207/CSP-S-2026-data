#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],l[500005]={},ans[300005],k[300005],cnt=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag;
			for(int w=1;w<=cnt;w++){
				if(ans[w]==j){
					flag=true;
					break;
				}
			}
			if(flag==false){
				cnt++;
				ans[cnt]=j;
			}
			if(l[a[j]]==0){
				l[a[j]]=j;
			}
			else{
				for(int z=l[a[j]];z>j;z--){
					ans[z]=0;
					cnt--;
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			k[j]++;
			ans[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
    return 0;
}
