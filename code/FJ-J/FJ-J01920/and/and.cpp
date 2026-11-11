#include<bits/stdc++.h>
using namespace std;
int n;
long long maxm=-999,now,q,x[201010],y[201010],k=1,m;
vector<long long>a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>now;
		a.push_back(now);
	}
	for(int i=1;i<=m;i++){
		k=k*(1+n-i);
	}
	for(int e=1;e<=k;e++){
    	for(int i=1;i<=m;i++){
    		for(int o=1;o<=n;o++){
    			if(x[o]==0){
    				y[q]=a[o];
    				q+=1;
    				x[o]=1;
				} 
			}
		}
		for(int i=1;i<=m;i++){
			if(i=1){
				now=y[i];
			}else{
				now=now&y[i];
			}
		}
		if(now>=maxm){
			maxm=now;
		}
	}
	cout<<maxm;
	return 0;
}

