#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int w[500001];
int minn=1e9;
struct rail{
	int a[500001];
	int k;
};
rail ra[501];
void find2(int x,int y,int z){
	for(int i=1;i<=n;i++){
		bool f=0,f1=0;
		for(int j=1;j<=ra[i].k;j++){
		    if(ra[i].a[j]==x){
		    	f=1;
			}
			if(ra[i].a[j]==y){
		    	f1=1;
			}
	    }
	    if(f&&f1){
	    	minn=min(minn,z);
	    	return;
		}
	}
	for(int i=1;i<=n;i++){
		bool f2=0;
		for(int j=1;j<=ra[i].k;j++){
		    if(ra[i].a[j]==x){
		    	f2=1;
			}
	    }
	    if(f2){
	    	for(int j=1;j<=ra[i].k;j++){
		        if(ra[i].a[j]!=x){
		    	    find(ra[i].a[j],y,z+1);
			    }
	        }
		}
	}
	return;	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
		for(int i=1;i<=m;i++){
		    scanf("%d",&w[i]);
	    }
	    int t;
	    for(int i=1;i<=n;i++){
		    scanf("%d",&ra[i].k);
		    for(int j=1;j<=2*ra[i].k;j++){
			    scanf("%d%d",&ra[i].a[j],&t);
		    }
	    }
	    for(int i=1;i<=q;i++){
	    	minn=1e9;
	    	int x,y;
	    	scanf("%d%d",&x,&y);
	    	find2(x,y,1);
	    	printf("%d/n",(minn*2*t+w[x]+w[y]));
		}
	return 0;
} 
