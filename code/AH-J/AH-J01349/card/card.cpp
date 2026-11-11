#include<bits/stdc++.h>
using namespace std;
int k=0,n,m,a[60066],lin=1,ans[60066],c=0,s=1;
char ss[30066]={0,0,0,0};
int cc(){
	int z=1;
	while(ans[z]!=0){
		z++,c++;
	}
	return c;
}
int cha(){
	c=cc();
	for(int u=1;u<=m;++u){
		for(int p=1;p<=c;++p){
			if(ans[p]=u){
				ss[u]++;
			}
		}
	}
}
int chong(int l){
	int ll=a[l];
	for (int j=l+1;j<=n;++j){
		if(a[j]==ll)return j;
	}
	k++;
	return lin;
}
int main(){ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin >>a[i];
    for(int i=1;i<=n;++i){
    	lin=i;
    	while(lin<n){
    	lin=chong(lin);
    	cout <<k<<endl;
    	if(k==1){
    		k=0;
    		ans[s]=a[lin];
    		s++;
		    lin++;
		}
		}
		//cout<<s<<endl;
		//for(int r=1;r<=m;++r)cout <<ans[r];
		cha();
	}
	for(int i=1;i<=m;++i)cout <<ss[i];
	return 0;
} 
