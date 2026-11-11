#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num[300005],num1[300005],ln[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		num[a[i]]++;
		ln[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			a[j]=b[j];
		}
		num[b[i-1]]--;
		for(int j=1;j<=m;j++)num1[a[j]]=num[a[j]];
		for(int j=i;j<=n;j++){
			if(num1[a[j]]>1){
				int t=a[j];
				for(int k=j;k<ln[t];k++){
					a[k]=0;
					num1[a[k]]--;
					j=k;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
	return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int fnt[500005],num[300005],ans[300005];//fnt:first no time最晚消失局数; 
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	int ft=0,fn=0;
	for(int i=1;i<=n;i++){
		fnt[i]=ft;
		if(fn==a[i])ft=a[i];
		if(!ft){
			if(num[a[i]]>1){
				num[a[i]]--;
				ft=i;
				fn=a[i];
			}
		}
		else {
			num[a[i]]--;
		}
		if(num[fn]==0)ft=0,fn=0,fnt[i]=0;
	}
	for(int i=1;i<=n;i++)cout<<fnt[i]<<' ';
	return 0;
}*/


