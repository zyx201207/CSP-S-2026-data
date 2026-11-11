#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define ll long long
ll c,t,n,d,i,j,x,y,a[N],s1,s2,m,w,ans,f,z;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(1<=c&&c<=10){
		while(t--){
			cin>>n>>d>>x;
			for(i=1;i<n;i++){
				cin>>y;
				a[i]=y-x;
				x=y;
			}
			ans=0;
			for(i=1;i<n;i++){
				s1=s2=f=0;
				for(j=i;j<n-1;j++){
					if(a[i]>d)break;
					if(s1+a[i]>d||s2){
						if(s2==0)x=i-1;
						if(s2+a[i]<=d)s2+=a[i];
						else{
							if(!f){
								if(s2+a[x]<=d&&(s2+a[x-1]>d||x-1==j-1)){ans++;f=1;}
								else if(s2+a[x]<=d&&s2+a[x]+a[x-1]<=d){
									break;
								}
								else{
									if(f)ans++;
									s1=s2=0;
								}
							}
						}
					}
					else s1+=a[i];
				}
			}
			cout<<ans<<"\n";
		}
	}
	if(c==0||11<=c&&c<=12){
		while(t--){
			cin>>n>>d>>x;
			ans=0;
			for(i=1;i<n;i++){
				cin>>y;
				w=a[i]=y-x;
				x=y;
			}
			x=d/w*w;
			for(i=2;i<n;i++){
				y=i*w/x;
				z=i*w%x;
				if(z>=w&&z<2*w&&z+w<=d&&y==1){
					ans+=n-i+1;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
