#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	int a[150000]={0},b[150000]={0},c=0,dick=1,d[150000],e=1;
	for(int o=1;o<=n;o++){
		cin>>d[o];
	}
	for(int o=1;o<=n;o++){
		for(int i=e;i<=n;i++){
		    b[dick]=d[i];
		    for(int j=1;j<dick;j++){
			    if(b[j]==b[dick]){
				    for(int k=1;k<dick;k++){
					    b[k]=0;
				    }
				b[1]=b[dick];b[dick]=0;dick=2;c=1;break;
			    }
		    }
		    if(c==0)dick++;
	        c=0;
		}
		for(int i=1;i<=n;i++){
			a[b[i]]=a[b[i]]+1;
		}e++;dick=1;
	    for(int i=1;i<=n;i++)b[i]=0;
    }
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
}
