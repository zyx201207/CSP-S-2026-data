#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],x[500010],ans[500010],cd;
void change(int sx){
	int bg=0,cha[500010];
	for(int i=1;i<=cd;i++){
		if(x[i]==sx)bg=i;
	}
	if(bg==0){
		x[cd+1]=sx;
		cd++;
		
		return ;
	}
	else {
		cd=bg;
		for(int i=1;i<=cd;i++){
			cha[i]=x[i];
		}
		memset(x,0,sizeof(x));
		for(int i=1;i<=cd;i++){
			x[i]=cha[i];
		}
		
		memset(cha,0,sizeof(cha));
	}
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof(x));
		int ss=0;
		for(int j=i;j<=n;j++){
			x[++ss]=a[j];
		}
		cd=n-i+1;
		for(int j=i;j<=n;j++){
			change(a[j]);
		}
		for(int j=1;j<=cd;j++){
			ans[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
