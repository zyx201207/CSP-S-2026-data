#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct plan{
	int f;
	int t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int a1[1005]={0};
    int t1[1005]={0};
    int a2[1005]={0};
    int t2[1005]={0};
    plan p[1005]={};
    int w[6]={0};
    int ww[6]={0};
    int www[6][6]={{0}};
    
    int wwws=0;
    int dao[100][100]={{0}};
    for(int i=0;i<5;i++){
    	cin>>w[i];
	}
    int k;
    cin>>k;
    int pa1=0,pa2=0;
    for(int j=0;j<k;j++){
    	cin>>a1[j];
		cin>>t1[j];
		dao[pa1][a1[j]]=1;
		ww[a1[j]]=t1[j];
		pa1=a1[j];
	}
	for(int i=1;i<n;i++){
	    cin>>k;
        for(int j=0;j<k;j++){
        	cin>>a2[j];
        	cin>>t2[j];
        	if(ww[a2[j]]!=0) {
        		www[i][i+1]=ww[a2[j]]+t2[j];
        		
        		wwws=max(wwws,www[i][i+1]);
	    	}else{
	    		ww[a2[j]]=t2[j];
	    	}
		    dao[pa1][a1[j]]=1;
        	
        	pa2=a2[j];
	    }	
	}
	
	
	for(int i=0;i<q;i++){
		cin>>p[i].f;
		cin>>p[i].t;
	}
	for(int i=0;i<q;i++){
		int ans=0;
		int aa=p[i].f;
		int bb=p[i].t;
		//cout<<ww[aa]<<" "<<ww[bb]<<endl;
		ans=w[aa-1]+w[bb-1];//chumen
		ans=ans+ww[aa]+ww[bb];//daozhan
		if(dao[aa][bb]==0){
			ans+=wwws;
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
