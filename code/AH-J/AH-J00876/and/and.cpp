#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,v[200001];
int a[200001],maxx=0,b[32],max2=0;
int y(int q,int p){
	int z=0;
    for(int i=t;i>=1;i--){
		int q1=0,p1=0;
	    if(q>=b[i]){
		    q-=b[i];
		    q1=1;	
		}if(p>=b[i]){
		    p-=b[i];
		    p1=1;	
		}if(q1==1&&p1==1)z+=b[i];
	}	
	return z;
}
void dfs(int x,int ad){
	if(x-1==m){
	    if(ad>max2)max2=ad;	
	    return;
	}
	for(int i=1;i<=n;i++){
	    if(v[i]!=1){
			if(x==1)ad=a[i];
		    v[i]=1;
		    dfs(x+1,y(ad,a[i]));
		    v[i]=0;	
		}
	}
}
int main(){
    freopen("and.in","r",stdin);    
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>a[i];	
	    if(maxx<a[i])maxx=a[i];
	}
	if(m==1){
	    cout<<maxx;
	    return 0;	
	}
	for(int i=1;i<=maxx;i*=2){
		b[++t]=i;
	}
	b[1]=1;
	dfs(1,0);
	cout<<max2;
    return 0;
}
