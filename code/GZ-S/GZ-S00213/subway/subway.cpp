//遵义市第四中学 陈文涛 GZ-S00213
#include <bits/stdc++.h>
using namespace std;


long long c1,n,m,d1,q,len1=0,len2=0,len3=0;
long long a[14];
long long b[14],b1[14];
long long c[14],c1[14];
long long d[14],d1[14];


int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<' ';
		int x;
		cin>>x;
		if(i==1){
			for(int j=1;j<=x;j++){
				cin>>b1[j];
				cin>>b[b1[j]];
				len1++;
			}
		}else if(i==2){
			for(int j=1;j<=x;j++){
				//cout<<j<<' ';
				cin>>c1[j];
				cin>>c[c1[j]];
				len2++;
			}
		}else if(i==3){
			for(int j=1;j<=x;j++){
				cin>>d1[j];
				cin>>d[d1[j]];
				len3++;
			}
		}
		//cout<<len1<<' '<<len2<<' '<<len3<<endl;
	}

	/*for(int i=1;i<=len1;i++){
		cout<<b[i]<<' ';
	}cout<<endl;
	for(int i=1;i<=len2;i++){
		cout<<c[i]<<' ';
	}*/

	for(int i=1;i<=q;i++){
		//cout<<i;
		int x,y;
		cin>>x>>y;
		int zt1=0,zt2=0;
		for(int j=1;j<=len1;j++){
			if(b1[j]==x) zt1=1;
			if(b1[j]==y) zt2=1;
		}for(int j=1;j<=len2;j++){
			if(c1[j]==x) zt1=2;
			if(c1[j]==y) zt2=2;
		}for(int j=1;j<=len3;j++){
			if(d1[j]==x) zt1=3;
			if(d1[j]==y) zt2=3;
		}//cout<<zt1<<' '<<zt2<<endl;
		if(zt1==zt2){
			if(zt1==1){
				cout<<a[x]+a[y]+b[x]+b[y]<<endl;
			}if(zt1==2){
				cout<<a[x]+a[y]+c[x]+c[y]<<endl;
			}if(zt1==3){
				cout<<a[x]+a[y]+d[x]+d[y]<<endl;
			}
		}else{
			if(zt1==1 && zt2==2){
				int ans=a[x]+a[y]+b[x]+c[y];
				for(int i=1;i<=len1;i++){
					for(int j=1;j<=len2;j++){
						if(b1[i]==c1[j]){
							cout<<ans+b[b1[i]]+c[c1[j]]<<endl;
						}
					}
				}
			}else if(zt1==2 && zt2==3){
				int ans=a[x]+a[y]+c[x]+d[y];
				for(int i=1;i<=len2;i++){
					for(int j=1;j<=len3;j++){
						if(c1[i]==d1[j]){
							cout<<ans+c[c1[i]]+d[d1[j]]<<endl;
						}
					}
				}
			}else if(zt1==1 && zt2==3){
				int ans=a[x]+a[y]+b[x]+d[y];
				for(int i=1;i<=len1;i++){
					for(int j=1;j<=len3;j++){
						if(b1[i]==d1[j]){
							cout<<ans+b[b1[i]]+d[d1[j]]<<endl;
						}
					}
				}
			}else if(zt1==2 && zt2==1){
				int ans=a[x]+a[y]+c[x]+b[y];
				for(int i=1;i<=len2;i++){
					for(int j=1;j<=len1;j++){
						if(c1[i]==b1[j]){
							cout<<ans+c[c1[i]]+b[b1[j]]<<endl;
						}
					}
				}
			}else if(zt1==3 && zt2==2){
				int ans=a[x]+a[y]+d[x]+c[y];
				for(int i=1;i<=len3;i++){
					for(int j=1;j<=len2;j++){
						if(d1[i]==c1[j]){
							cout<<ans+d[d1[i]]+c[c1[j]]<<endl;
						}
					}
				}
			}else if(zt1==3 && zt2==1){
				int ans=a[x]+a[y]+d[x]+b[y];
				for(int i=1;i<=len3;i++){
					for(int j=1;j<=len1;j++){
						if(d1[i]==b1[j]){
							cout<<ans+d[d1[i]]+b[b1[j]]<<endl;
						}
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


