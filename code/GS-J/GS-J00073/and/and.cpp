#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
	}
	if(m==2){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=max(a[i]&a[j],x);
			}
		}
	}
	if(m==3){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    x=max(a[i]&a[j]&a[k],x);
				}
			}
		}
	}
	if(m==4){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    for(int b=k+1;b<=n;b++){
				        x=max(a[i]&a[j]&a[k]&a[b],x);
				    }
				}
			}
		}
	}
	if(m==5){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    for(int b=k+1;b<=n;b++){
				    	for(int c=b+1;c<=n;c++){
			                x=max(a[i]&a[j]&a[k]&a[b]&a[c],x);
			            }
			        }
				}
			}
		}
	}
	if(m==6){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    for(int b=k+1;b<=n;b++){
				    	for(int c=b+1;c<=n;c++){
				    		for(int d=c+1;d<=n;d++){
			                    x=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d],x);
			                }
			            }
			        }
				}
			}
		}
	}
	if(m==7){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    for(int b=k+1;b<=n;b++){
				    	for(int c=b+1;c<=n;c++){
				    		for(int d=c+1;d<=n;d++){
				    			for(int e=d+1;e<=n;e++){
			                        x=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e],x);
			                    }
			                }
			            }
			        }
				}
			}
		}
	}
	if(m==8){
		x=-100;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    for(int b=k+1;b<=n;b++){
				    	for(int c=b+1;c<=n;c++){
				    		for(int d=c+1;d<=n;d++){
				    			for(int e=d+1;e<=n;e++){
				    				for(int f=e+1;f<=n;f++){
			                            x=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e],x);
			                        }
			                    }
			                }
			            }
			        }
				}
			}
		}
	}
	cout<<x;
	return 0;
}
