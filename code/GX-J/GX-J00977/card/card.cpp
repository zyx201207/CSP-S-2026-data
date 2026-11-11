#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		int h[500010],rm[500010];
		for(int j=1;j<=n;j++)t[j]=0,h[j]=0,rm[j]=0;
		for(int j=i;j<=n;j++){t[a[j]]++;if(t[a[j]]>=2)h[a[j]]=1;}
		for(int j=1;j<=n;j++)t[j]=0;
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			//<<j<<" "<<t[a[j]]<<endl;
			if(h[a[j]]==1&&t[a[j]]>=2)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[k]==a[j]&&rm[k]==0){rm[k]=1;if(t[a[k]]>0)t[a[k]]--;break;}
					rm[k]=1;if(t[a[k]]>0)t[a[k]]--;
				}
			}
		}
		//for(int j=i;j<=n;j++)cout<<rm[j]<<"|"<<a[j]<<" ";
		//cout<<endl;
		for(int j=i;j<=n;j++)if(rm[j]==0)ans[a[j]]++;
		//for(int j=1;j<=m;j++)cout<<ans[j]<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
//6767676767
