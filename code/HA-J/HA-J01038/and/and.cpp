#include <bits/stdc++.h>
using namespace std;
int n,m,ans,maxx=-912783,cmt=1;
int a[200090];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==n){
		long long l=a[1];
		for(int i=2;i<=n;i++){
			l&=a[i];
		}cout<<l;
		return 0;
	}if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					int l=a[i];
					l&=a[j];
					maxx=max(maxx,l);
				}	
			}
		}cout<<maxx;
		return 0;
	}if(m==n-1){
		for(int i=1;i<=n;i++){
			int l;
			if(i==1) l=a[2];
			else l=a[1];
			for(int j=2;j<=n;j++){
				if(i!=j&&(i!=1&&j!=2)){
					l&=a[j];
				}
			}
			maxx=max(l,maxx);
		}cout<<maxx;
		return 0;
	}
	if(n<=20){
		int sta;
		for(int i=1;i<=n;i++){sta=a[i];
		for(int j=i+1;j<=n;j++){sta&=a[j];if(j>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int q=j+1;q<=n;q++){sta&=a[q];if(q>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int w=q+1;w<=n;w++){sta&=a[w];if(w>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int e=w+1;e<=n;e++){sta&=a[e];if(e>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int r=e+1;r<=n;r++){sta&=a[r];if(r>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int t=r+1;t<=n;t++){sta&=a[t];if(t>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int y=t+1;y<=n;y++){sta&=a[y];if(y>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int u=y+1;u<=n;u++){sta&=a[u];if(u>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int o=u+1;o<=n;o++){sta&=a[o];if(o>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int p=o+1;p<=n;p++){sta&=a[p];if(p>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int s=p+1;s<=n;s++){sta&=a[s];if(s>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int d=s+1;d<=n;d++){sta&=a[d];if(d>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int f=d+1;f<=n;f++){sta&=a[f];if(f>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int g=f+1;g<=n;g++){sta&=a[g];if(g>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int h=g+1;h<=n;h++){sta&=a[h];if(h>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int k=h+1;k<=n;k++){sta&=a[k];if(k>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int z=k+1;z<=n;z++){sta&=a[z];if(z>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int x=z+1;x<=n;x++){sta&=a[x];if(x>=m){maxx=max(maxx,sta);sta=-1;break;}
		for(int c=x+1;c<=n;c++){sta&=a[c];if(c>=m){maxx=max(maxx,sta);sta=-1;break;}
		}}}}}}}}}}}}}}}}}}}}cout<<maxx;
	}
	return 0;
}
