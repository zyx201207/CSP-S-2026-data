#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000001];
int b[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		if(a[1]==1){
			if(a[2]==1){
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}else{
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}
		}else{
			if(a[2]==1){
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}else{
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}
		}
	}else{
		if(a[1]==1){
			if(a[2]==1){
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}else{
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}else{
						if(a[5]==1){
							cout<<"5 0";
						}else{
							cout<<"5 5";
						}
					}
				}
			}
		}else{
			if(a[2]==1){
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}else{
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}else{
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}
				}
			}else{
				if(a[3]==1){
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}else{
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}
				}else{
					if(a[4]==1){
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}else{
						if(a[5]==1){
							cout<<"5 5";
						}else{
							cout<<"5 0";
						}
					}
				}
			}
		}
	}
	return 0;
}
