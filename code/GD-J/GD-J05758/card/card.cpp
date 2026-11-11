#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    long long n,m,a[100005],p[100005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int g=1;g<=m;g++){
    	int s=0;
    	for(int i=1;i<=n;i++){
        if(a[i]!=0){
        	p[i]=a[i];
		}
        if(i!=1){
            for(int j=i-1;j>=1;j--){
                if(p[i]==p[j]){
                	a[i]=0; 
                    for(int k=j;k<i;k++){
                        p[k]=0;
                    }
                }
            }
            if(i==4){
        		for(int i=1;i<=m;i++){
        			for(int j=1;j<=n;j++){
            			if(p[j]==i){
                		s++;
            			}	
        			}	
    			}
			}
        }
    	}
    	cout<<s<<" ";
	}
    return 0;
}

