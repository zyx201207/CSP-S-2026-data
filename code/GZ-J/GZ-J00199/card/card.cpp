//GZ-J00199 遵义市第一初级中学 刘致江 
#include<bits/stdc++.h>
using namespace std;
struct You{
	int hao;
	bool zai;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,shu1=1;
	cin>>n>>m;
	int a[n+1],count[m+1]={0},shu[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	You b[m+1];
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=m;k++){
		if(b[k].zai=true){
			b[k].zai=false;
			b[a[k]].hao=k;
			shu[shu1]=a[k];
			shu1++;
		}else{
			for(int j=b[a[k]].hao;j<=shu1;j++){
				b[a[j]].zai=true;
				shu[j]=0;
			}
			shu1=b[a[k]].hao;
			b[k].zai=false;
			b[a[k]].hao=k;
			shu[shu1]=a[k];
			shu1++;
		}
		if(i==n){
			for(int j=1;j<=shu1;shu1++){
				count[shu[j]]=count[shu[j]]+1;
			}
			b[m]={true};
		}	
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<count[i]<<" ";
	}
	return 0;
}
