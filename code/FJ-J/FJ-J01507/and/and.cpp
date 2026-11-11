#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;

for(int i=1;i<=n;i++){
	cin>>a[i];
	maxx=max(maxx,a[i]);
}


if(m==1){
	cout<<maxx;
	return 0;
}

if(n<=2000&&m==1){
	cout<<maxx;
	return 0;
}

if(n<=2000&&m==n){
	int maxx=a[1]&a[2];
	for(int i=3;i<=n;i++){
		maxx=maxx&a[i];
	}
	cout<<maxx;
	return 0;
}

if(n<=2000&&m==2){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}



if(m==n){
	int maxx=a[1]&a[2];
	for(int i=3;i<=n;i++){
		maxx=maxx&a[i];
	}
	cout<<maxx;
	return 0;
}



if(n<=20&&m==1){
	cout<<maxx;
	return 0;
}
if(n<=20&&m==2){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==3){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			maxx=max(maxx,a[i]&a[j]&a[ii]);
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==4){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++)
			maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]);
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==5){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++)
				maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]);
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==6){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++)
					maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]);
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==7){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++)
						maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]);
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==8){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++)
							maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]);
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==9){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==10){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==11){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==12){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==13){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==14){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==15){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==16){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								for(int yy=xx+1;yy<=n;yy++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]&a[yy]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==17){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								for(int yy=xx+1;yy<=n;yy++)
								for(int xxx=yy+1;xxx<=n;xxx++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]&a[yy]&a[xxx]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==18){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								for(int yy=xx+1;yy<=n;yy++)
								for(int xxx=yy+1;xxx<=n;xxx++)
								for(int yyy=xxx+1;yyy<=n;yyy++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]&a[yy]&a[xxx]&a[yyy]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==19){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								for(int yy=xx+1;yy<=n;yy++)
								for(int xxx=yy+1;xxx<=n;xxx++)
								for(int yyy=xxx+1;yyy<=n;yyy++)
								for(int xxxx=yyy+1;xxxx<=n;xxxx++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]&a[yy]&a[xxx]&a[yyy]&a[xxxx]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
if(n<=20&&m==20){
maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int ii=j+1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				for(int iii=jj+1;iii<=n;iii++){
					for(int jjj=iii+1;jjj<=n;jjj++){
						for(int iiii=jjj+1;iiii<=n;iiii++){
							for(int jjjj=iiii+1;jjjj<=n;jjjj++){
								for(int iiiii=jjjj+1;iiiii<=n;iiiii++)
								for(int jjjjj=iiiii+1;jjjjj<=n;jjjjj++)
								for(int iiiiii=jjjjj+1;iiiiii<=n;iiiiii++)
								for(int jjjjjj=iiiiii+1;jjjjjj<=n;jjjjjj++)
								for(int x=jjjjjj+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)
								for(int xx=y+1;xx<=n;xx++)
								for(int yy=xx+1;yy<=n;yy++)
								for(int xxx=yy+1;xxx<=n;xxx++)
								for(int yyy=xxx+1;yyy<=n;yyy++)
								for(int xxxx=yyy+1;xxxx<=n;xxxx++)
								for(int yyyy=xxxx+1;yyyy<=n;yyyy++)
								maxx=max(maxx,a[i]&a[j]&a[ii]&a[jj]&a[iii]&a[jjj]&a[iiii]&a[jjjj]&a[iiiii]&a[jjjjj]&a[iiiiii]&a[jjjjjj]&a[x]&a[y]&a[xx]&a[yy]&a[xxx]&a[yyy]&a[xxxx]&a[yyyy]);
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		}
	}
	cout<<maxx;
	return 0;
}
	return 0;
}
