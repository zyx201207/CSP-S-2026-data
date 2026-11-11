#include<bits/stdc++.h>
using namespace std;
struct xinxi{
	long long zuobiao,maxx=0,duan,lujing=0;
}a[2000005];
long long c,t,n,d,x=0,y=1,type1=1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		x=0,y=1;
		cin>>a[1].zuobiao>>a[2].zuobiao;
		int ty1=a[2].zuobiao-a[1].zuobiao;
		for(int i=3;i<=n;i++){
			cin>>a[i].zuobiao;
			if(a[i].zuobiao-a[i-1].zuobiao!=ty1) type1=0;
		}
		if(type1==1){
			int zu;
			zu=d/ty1*2;
			if(n>=zu) x=n-zu+1;
			else x=0;
		}
		else{
			for(int i=1;i<=n;i++){			
				a[i].duan=n+1;
				while(y<i){
					if((a[i].zuobiao-a[y].zuobiao)<=d){
						for(int j=y;j<i;j++){
							a[j].maxx=i;
						}
						break;
					}
					else y++;
				}
			}
			for(int p=1;p<=n-3;p++){			
				for(int i=p;i<=n;i++){
					a[i].duan=n+1;
					a[i].lujing=0;
				}
				a[p].duan=0;
				for(int i=p;i<=n;i++){
					for(int j=i+1;j<=a[i].maxx;j++){
						if(a[i].duan+1<a[j].duan) a[j].duan=a[i].duan+1,a[j].lujing=1;
						else if(a[i].duan+1==a[j].duan) a[j].lujing+=1;
						else if(a[i].duan+1>a[j].duan) continue;
					}
					if(a[i].lujing==2) x++;
				}
			}			
		}
		cout<<x<<endl;
	}
	
	return 0;
}
