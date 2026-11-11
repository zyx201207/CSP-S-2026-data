#include<iostream>
using namespace std;
int c,n,m,d,q,sum;
int w[500001],k[501],a[501][500001],t[501][500001],x,y,way,way1;
int main(){
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
     cin>>c>>n>>m>>d>>q;
     for(int i=1;i<=m;i++){
     	cin>>w[i];
     }
     for(int i=1;i<=n;i++){
     	cin>>k[i];
     	for(int j=1;j<=k[i];j++){
     		cin>>a[i][j]>>t[i][j];
     	}
}
      for(int i=1;i<=q;i++){
      	 cin>>x>>y;
      	 sum=w[x]+w[y];
      	 for(int j=1;j<=n;j++){
      	 	int qwe=0;
      	 	for(int o=1;o<=k[j];o++){
      	 			if(x==a[j][o]){
      	     	        way=j;
      	     	        qwe++;
      	     	        sum+=t[j][o];
			        }
			        if(y==a[j][o]){
			    	    way1=j;
			    	    qwe++;
			    	    sum+=t[j][o];
			        }
			        if(qwe==2){
			        	break;
			        }
      	     }
      	     cout<<sum<<endl;
      }
}
     fclose(stdin);
     fclose(stdout);
     return 0;
}
