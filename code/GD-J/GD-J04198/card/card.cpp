#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],la[300007],ans[300007],sum[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1])fl=1;
		sum[a[i]]++;
	}
	if(n>5&&m==2){
		if(a[n]==2)cout<<sum[1]<<" "<<n;
		else cout<<n<<" "<<sum[2];
		return 0;
	}
	if(!fl){
		int s=0;
		for(int i=1;i<=n;i++){
			s++;
			if(a[i]!=a[i+1])cout<<s<<" ";
		}
		return 0;	
	}
	for(int i=1;i<=n;i++){
		memset(la,0,sizeof(la));
		for(int j=i;j<=n;j++){
			if(!la[a[j]])la[a[j]]=j;
			else{
				for(int k=la[a[j]];k<j;k++)la[a[k]]=0;
				la[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)if(la[j])ans[j]++;
	} 
	for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
	return 0;
}
