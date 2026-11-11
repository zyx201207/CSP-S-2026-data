#include<bits/stdc++.h>
using namespace std;
int n,m,a[750005],vid[750005],cnt[750005],ln=0,b[750005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(vid[a[i]]==0){
				b[++ln]=a[i];
				vid[a[i]]=ln;
			}else{
				for(int j=vid[a[i]]+1;j<=ln;j++){
					vid[b[j]]=0;
					b[j]=0;
				}
				ln=vid[a[i]];
				
			}
		}
		for(int i=1;i<=ln;i++){
			cnt[b[i]]++;
			vid[b[i]]=0;
			b[i]=0;
		}
		ln=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
