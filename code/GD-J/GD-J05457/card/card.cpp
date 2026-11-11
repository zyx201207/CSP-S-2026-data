#include<bits/stdc++.h>
using namespace std;
const int INF=1e6;
int n,m,l;
int a[INF];
int sum[INF];
struct table{
	int num;
	bool v=0;
}t[INF];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=INF;j++){
		    t[j].num=0;
	    	t[j].v=0;
    	}
    	l=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=l;k++){
				if(t[k].num==a[j]&&t[k].v==0){
					for(int x=k;x<=l;x++) t[x].v=1;
				}
			}
			t[++l].num=a[j];
			t[l].v=0;
			
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=l;k++){
				if(t[k].num==j&&t[k].v==0){
					sum[j+1]+=1;
					break;
				}
			}
		}
	}
	for(int i=2;i<=m+1;i++) cout<<sum[i]<<" ";
	return 0;
}
