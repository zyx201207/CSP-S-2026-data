#include<bits/stdc++.h>
using namespace std;
long long n,sum,c,zy=2;//0×ó1ÓÒ2ÏàµÈ 
char cf;
struct chuan{
	long long gs;
	char zf;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].zf;
	}
	for(int i=0,j=n+1;i<j;){
		if(zy==0){
			j--;
			if(i>=j)break; 
			if(c<a[j].gs){
				zy=1;
				if(cf!=a[j].zf){
					cf=a[i].zf;
					sum+=c;
				}
				c=a[j].gs-c;
			}else if(c>a[j].gs){
				zy=0;
				if(cf!=a[j].zf){
					sum+=a[j].gs;
				}
				c=c-a[j].gs;
			}else{
				zy=2;
				if(cf!=a[j].zf){
					sum+=c;
				}
				c=0;
			}
//			cout<<sum<<' '<<i<<' '<<j<<' '<<c<<' '<<cf<<' '<<zy<<'\n';
		}else if(zy==1){
			i++;
			if(i>=j)break; 
			if(c<a[i].gs){
				zy=0;
				if(cf!=a[j].zf){
					cf=a[i].zf;
					sum+=c;
				}
				c=a[j].gs-c;
			}else if(c>a[i].gs){
				zy=1;
				if(cf!=a[j].zf){
					sum+=a[j].gs;
				}
				c=c-a[j].gs;
			}else{
				zy=2;
				if(cf!=a[j].zf){
					sum+=c;
				}
				c=0;
			}
//			cout<<sum<<' '<<i<<' '<<j<<' '<<c<<' '<<cf<<' '<<zy<<'\n';
		}else{
			i++,j--;
			if(i>=j)break; 
			if(a[i].zf==a[j].zf){
				cf=a[i].zf;
				if(a[i].gs>a[j].gs){
					zy=0;
					c=a[i].gs-a[j].gs;
				}else if(a[i].gs<a[j].gs){
					zy=1;
					c=a[j].gs-a[i].gs;
				}else{
					zy=2;
				}
			}else{
				if(a[i].gs>a[j].gs){
					zy=0;
					c=a[i].gs-a[j].gs;
					cf=a[1].zf;
					sum+=a[j].gs;
				}else if(a[i].gs<a[j].gs){
					zy=1;
					c=a[j].gs-a[i].gs;
					cf=a[j].zf;
					sum+=a[i].gs;
				}else{
					sum+=a[i].gs;
					zy=2;
				}
//				cout<<sum<<' '<<i<<' '<<j<<' '<<c<<' '<<cf<<' '<<zy<<'\n';
			}
		}	
	}
	cout<<sum;
	return 0;
}
