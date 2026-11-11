#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0,sum=0,l=0,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long idl=1,idr=n,ls=0,rs=0;
	r=sum;
	while(l<r&&idl<idr){
		if(ls==0&&rs==0){
			if(c[idl]==c[idr]){
				if(a[idl]==a[idr]) idl+=1,idr-=1,l+=a[idl-1],r-=a[idr+1];
				else{
					if(a[idl]<a[idr]){
						idl+=1,l+=a[idl-1],r-=a[idl-1],rs=(a[idr]-a[idl-1]);
					}else{
						idr-=1,r-=a[idr+1],l+=a[idr+1],ls=(a[idl]-a[idr+1]);
					}
				}
			}else{
				ans+=min(a[idr],a[idl]);
				if(a[idl]==a[idr]) idl+=1,idr-=1,l+=a[idl-1],r-=a[idr+1];
				else{
					if(a[idl]<a[idr]){
						idl+=1,l+=a[idl-1],r-=a[idl-1],rs=(a[idr]-a[idl-1]);
					}else{
						idr-=1,r-=a[idr+1],l+=a[idr+1],ls=(a[idl]-a[idr+1]);
					}
				}
			}
		}else{
			if(ls!=0){
				if(c[idl]==c[idr]){
					if(ls==a[idr]){
					    l+=ls,idr--,r-=ls,ls=0,idl++;
				    }else{
				    	if(ls<a[idr]){
				    		idl+=1,l+=ls,r-=ls,rs=a[idr]-ls,ls=0;
						}else{
						    r-=a[idr],l+=a[idr],ls-=a[idr],idr--;
						}
				    }
				}else{
					ans+=min(a[idr],ls);
					if(ls==a[idr]){
					    l+=ls,idr--,r-=ls,ls=0,idl++;
				    }else{
				    	if(ls<a[idr]){
				    		idl+=1,l+=ls,r-=ls,rs=a[idr]-ls,ls=0;
						}else{
						    r-=a[idr],l+=a[idr],ls-=a[idr],idr--;
						}
				    }
				}
			}else{
				if(c[idl]==c[idr]){
					if(rs==a[idl]){
						l+=rs,r-=rs,idr--,idl++,rs=0;
					}else{
						if(rs<a[idl]){
							idr--,r-=rs,l+=rs,ls=a[idl]-rs,rs=0;
						}else{
							r-=a[idl],l+=a[idl],rs-=a[idl],idl++;
						}
					}
				}else{
					ans+=min(rs,a[idl]);
					if(rs==a[idl]){
						l+=rs,r-=rs,idr--,idl++,rs=0;
					}else{
						if(rs<a[idl]){
							idr--,r-=rs,l+=rs,ls=a[idl]-rs,rs=0;
						}else{
							r-=a[idl],l+=a[idl],rs-=a[idl],idl++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
