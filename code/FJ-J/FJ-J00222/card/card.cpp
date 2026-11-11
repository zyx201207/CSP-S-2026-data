#include<bits/stdc++.h>
using namespace std;

int p[300100],p1[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p1[i];
	}
	for(int i=1;i<=n;i++){
	    int zm[300100]={0};
		for(int j=i;j<=n;j++){
			if(zm[p1[j]]!=0){
			    t=zm[p1[j]]+1;
				for(int x=1;x<=m;x++){
					if(zm[x]>=t){
						zm[x]=0;
					}
				}
			}else{
			    zm[p1[j]]=t;
			    t++;
			}
		}
		for(int j=1;j<=m;j++){
			if(zm[j]!=0){
				p[j]++;
			}
		}
		t=1;
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
