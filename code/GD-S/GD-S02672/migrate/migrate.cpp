#include<bits/stdc++.h>
using namespace std;
long long n,xa,xb,xc,xd,d,c,t,cnt,x[50005],l,r,ma,mb;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			cnt=0;
			if(n<=3){
				for(int i=0;i<n;i++){
					cin>>x[i];
				}
				cout<<0<<endl;
				continue;
			}
			else{
				cin>>xa>>xb>>xc>>xd;
				if(xd-xa>d && xd-xa<2*d){
					cnt++;
				}
				for(int i=4;i<n;i++){
					xa=xb;
					xb=xc;
					xc=xd;
					cin>>xd;
					if(xd-xa>d && xd-xa<2*d){
						cnt++;
					}
				}
				cout<<cnt<<endl;
			}
		}
	}
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		else{
			for(int i=0;i<n;i++){
				cin>>x[i];
			}
			l=0;r=0;ma=0;mb=0;
			for(;;){
				if(x[r]-x[l]<=d){
					r++;
				}
				else if(x[r]-x[l]>=2*d){
					l++;
				}
				else if(x[r]-x[mb]>d){
					mb++;
				}
				else if(x[mb]-x[ma]>d){
					ma++;
				}
				else if(x[ma]-x[l]>d){
					l++;
				}
				else if(l==ma){
					ma++;
				}
				else if(mb==ma){
					mb++;
				}
				else if(r==mb){
					r++;
				}
				else{
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
}
