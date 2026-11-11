#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[501]={},t1,t[501][501]={};
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[i][j]=10000;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t1;
			cin>>t[i][t1];
		}
	}
	int x,y;
	while(q>0){
		cin>>x>>y;
		q--;
		int tim=0,x1=x,i1=1;
		tim+=w[x];
		tim+=w[y];
		int min1[501]={};
		for(int i=1;i<=n;i++){
			if(t[i][x1]!=10000){
		        	min1[i1]+=t[i][x1];
		    	if(t[i][y]!=10000){
			        min1[i1]+=t[i][y];
			        i1++;
			        break;
	        	}else{
	    	    	for(int j=x1+1;j<=m;j++){
	    	    		if(t[i][j]!=10000)
	    	    		for(int k=i+1;k<=n;k++)
	    		    		if(t[k][j]!=10000){
	    		    			min1[i1]+=t[i][j];
	    		    			i=k-1;
	    			    		x1=j;
	    			    		break;
			    	    }
					}
		    	}
	    	}
    	}
		sort(min1+1,min1+n);
		cout<<tim+min1[1]<<endl;
	}
	return 0;
}

