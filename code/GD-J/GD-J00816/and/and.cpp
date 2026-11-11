#include<bits/stdc++.h>
#define int long long
using namespace std;
int pow2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
string tt(int n){
	string ans="";
	while(n>0){
		char c=(n%2+'0');
		ans=ans+c;
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int tt1(string a){
	int sum=0;
	for(int i=0;i<a.length();i++){
		sum+=((a[i]-'0')*pow2[i]);
	}
	return sum;
}
string a[200005];
signed main(){
	int n,m,ans=-1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int u;
		cin>>u;
		a[i]=tt(u);
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				string x=a[i],y=a[j],z="";
				reverse(x.begin(),x.end());
				reverse(y.begin(),y.end());
				for(int k=0;k<min(x.length(),y.length());k++){
					z+=x[k]&y[k];
				}
				ans=max(tt1(z),ans);
			}
		}
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					string x=a[i],y=a[j],z=a[k],e="";
					reverse(x.begin(),x.end());
					reverse(y.begin(),y.end());
					reverse(z.begin(),z.end());
					for(int l=0;l<min(min(x.length(),y.length()),z.length());l++){
						e+=(x[l]&y[l])&z[l];
					}
					ans=max(tt1(e),ans);
				}
			}
		}
	}else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						string x=a[i],y=a[j],z=a[k],aa[ii],e="";
						reverse(x.begin(),x.end());
						reverse(y.begin(),y.end());
						reverse(z.begin(),z.end());
						reverse(aa.begin(),aa.end());
						for(int l=0;l<min(min(min(x.length(),y.length()),z.length()),aa.length());l++){
							e+=((x[l]&y[l])&z[l])&aa[l];
						}
						ans=max(tt1(e),ans);
					}
				}
			}
		}
	}else if(m==5){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						for(int jj=0;jj<ii;jj++){
							string x=a[i],y=a[j],z=a[k],aa=a[ii],xx=a[jj],e="";
							reverse(x.begin(),x.end());
							reverse(y.begin(),y.end());
							reverse(z.begin(),z.end());
							reverse(aa.begin(),aa.end());
							reverse(xx.begin(),xx.end());
							for(int l=0;l<min(min(min(min(x.length(),y.length()),z.length()),aa.length()),xx.length());l++){
								e+=(((x[l]&y[l])&z[l])&aa[l])&xx[l];
							}
							ans=max(tt1(e),ans);
						}	
					}
				}
			}
		}
	}else if(m==6){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						for(int jj=0;jj<ii;jj++){
							for(int kk=0;kk<jj;kk++){
								string x=a[i],y=a[j],z=a[k],aa=a[ii],xx=a[jj],yy=a[kk],e="";
								reverse(x.begin(),x.end());
								reverse(y.begin(),y.end());
								reverse(z.begin(),z.end());
								reverse(aa.begin(),aa.end());
								reverse(xx.begin(),xx.end());
								reverse(yy.begin(),yy.end());
								for(int l=0;l<min(min(min(min(min(x.length(),y.length()),z.length()),aa.length()),xx.length()),yy.length());l++){
									e+=((((x[l]&y[l])&z[l])&aa[l])&xx[l])&yy[l];
								}
								ans=max(tt1(e),ans);
							}	
						}
					}
				}
			}
		}
	}else if(m==7){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						for(int jj=0;jj<ii;jj++){
							for(int kk=0;kk<jj;kk++){
								for(int iii=0;iii<kk;iii++){
									string x=a[i],y=a[j],z=a[k],aa=a[ii],xx=a[jj],yy=a[kk],zz[iii],e="";
									reverse(x.begin(),x.end());
									reverse(y.begin(),y.end());
									reverse(z.begin(),z.end());
									reverse(aa.begin(),aa.end());
									reverse(xx.begin(),xx.end());
									reverse(yy.begin(),yy.end());
									reverse(zz.begin(),zz.end());
									for(int l=0;l<min(min(min(min(min(min(x.length(),y.length()),z.length()),aa.length()),xx.length()),yy.length()),zz.length());l++){
										e+=(((((x[l]&y[l])&z[l])&aa[l])&xx[l])&yy[l])&zz[l];
									}
									ans=max(tt1(e),ans);
								}
							}	
						}
					}
				}
			}
		}
	}else if(m==8){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						for(int jj=0;jj<ii;jj++){
							for(int kk=0;kk<jj;kk++){
								for(int iii=0;iii<kk;iii++){
									for(int jjj=0;jjj<iii;jjj++){
										string x=a[i],y=a[j],z=a[k],aa=a[ii],xx=a[jj],yy=a[kk],zz[iii],xxx[jjj],e="";
										reverse(x.begin(),x.end());
										reverse(y.begin(),y.end());
										reverse(z.begin(),z.end());
										reverse(aa.begin(),aa.end());
										reverse(xx.begin(),xx.end());
										reverse(yy.begin(),yy.end());
										reverse(zz.begin(),zz.end());
										reverse(xxx.begin(),xxx.end());
										for(int l=0;l<min(min(min(min(min(min(min(x.length(),y.length()),z.length()),aa.length()),xx.length()),yy.length()),zz.length()),xxx.length());l++){
											e+=((((((x[l]&y[l])&z[l])&aa[l])&xx[l])&yy[l])&zz[l])&xxx[l];
										}
										ans=max(tt1(e),ans);
									}
								}
							}	
						}
					}
				}
			}
		}
	}else if(m==9){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					for(int ii=0;ii<k;ii++){
						for(int jj=0;jj<ii;jj++){
							for(int kk=0;kk<jj;kk++){
								for(int iii=0;iii<kk;iii++){
									for(int jjj=0;jjj<iii;jjj++){
										for(int kkk=0;kkk<jjj;kkk++){
											string x=a[i],y=a[j],z=a[k],aa=a[ii],xx=a[jj],yy=a[kk],zz[iii],xxx[jjj],yyy[kkk],e="";
											reverse(x.begin(),x.end());
											reverse(y.begin(),y.end());
											reverse(z.begin(),z.end());
											reverse(aa.begin(),aa.end());
											reverse(xx.begin(),xx.end());
											reverse(yy.begin(),yy.end());
											reverse(zz.begin(),zz.end());
											reverse(xxx.begin(),xxx.end());
											reverse(yyy.begin(),yyy.end());
											for(int l=0;l<min(min(min(min(min(min(min(min(x.length(),y.length()),z.length()),aa.length()),xx.length()),yy.length()),zz.length()),xxx.length()),yyy.length());l++){
												e+=(((((((x[l]&y[l])&z[l])&aa[l])&xx[l])&yy[l])&zz[l])&xxx[l])&yyy[l];
											}
											ans=max(tt1(e),ans);
										}
									}
								}
							}	
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 

