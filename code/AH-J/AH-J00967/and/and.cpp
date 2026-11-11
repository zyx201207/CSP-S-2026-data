#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
     int c,y,y1;
};
Node a[200005];
int b[200005],in=1;
bool cmp(Node x,Node y){
	if(x.y1!=y.y1){
		return x.y1>y.y1;
	}else{
	    return x.c>y.c;
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        int q=x;
        in=1;
        int o=0;
        while(x!=0){
           b[in++]=x%2;
           if(x%2==1){
		       o++;
		   }
           x/=2;
        }
        int u=0;
        for(int i=in-1;i>=1;i--){
		    u=u*10+b[i];
		}
		a[i].c=u,a[i].y=q,a[i].y1=o;
    }
    sort(a+1,a+n+1,cmp);
    int as;
    for(int i=1;i<m;i++){
		as=a[i].y&a[i+1].y;
	}
	cout<<as;
    return 0;
}
