#include <bits/stdc++.h>
using namespace std;
long long n,m,z,b;
int a[500005],ab[500005],o;

int main(){
    //freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ab[i]=a[i];
	}
	for(int c=1;c<=n;c++){
		for(int d=2;d<=n;d++){
			for(int e=1;e<d;e++){
		        for(int f=1;f<=e;f++){
		        	for(int i=1;i<=n;i++){
			            ab[i]=a[i];
		        	}
		        	z=m;
		            if(d==2){
		            	if(a[f]==a[f+1]){
		        	        if(d>b){
		        	        	b=d;
							}
		                }else{
			                for(int j=1;j<=z;j++){
			     	            if(ab[f]<ab[f+1]){
			    		            ab[f]+=1;
			    	            }else{
			    		            ab[f+1]+=1;
			    	            }
			    	            if(ab[f]==ab[f+1]){
			                        if(d>b){
		        	        	        b=d;
							        }
		    	                    break;
		                        }
		    	            }
		                }
					}else{
						for(int g=1;g<=d;g++){
			    	        if(ab[g]==ab[g+1]){
			    	        o++;
		                    }else{
							    break;
					    	}
						}
						if(o==d&&d>b){
		        	        	b=d;
		                }else{
			                for(int j=1;j<=z;j++){
			                	if(z<=0){
			                		break;
								}
			     	            if(ab[f]<ab[f+1]){
			    		            ab[f]++;
			    		            if(z>=f){
										z-=f;
									}else{
										break;
									}
									for(int m=1;m<=f;m++){
		                                a[m]=a[f];
	                                }
			    	            }else{
			    		            ab[f+1]++;
			    		            if(z>=1){
										z--;
									}else{
										break;
									}
			    	            }
			    	            o=0;
			    	            for(int g=1;g<=d;g++){
			    	            	if(ab[g]==ab[g+1]){
			    	            		o++;
		                            }else{
									    break;
									}
								}
								if(o==d&&d>b){
		        	        	    b=d;
								}
		    	            }
		                }
					}
	            }
			} 
	    }
	}
	cout<<b;
	return 0;
}
