//GZ-S00042 贵阳市观山湖区外国语实验中学 孙小涵 
#include<bits/stdc++.h>
using namespace std;
struct ii{
	int x,y;
}r[100005];
struct jj{
	int k;
	int a[500005],t[500005];
}s[505];
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin>>s[i].a[j]>>s[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	if(12<=c&&c<=19){
		long long c=0;
		int t=s[1].t[1];
		c+=t*2;
		for(int k=1;k<=q;k++){
			bool f=0;
			for(int i=1;i<=n;i++){
				if(s[i].a[1]!=r[k].x){
					continue;
				}
				int b=0;
				for(int j=2;j<=s[i].k;j++){
					if(s[i].a[j]<r[k].y){
						b=s[i].a[j];
					}
					else if(s[i].a[j]==r[k].y){
						cout<<c<<"\n";
						f=1;
						break;
					}
				}
			}
			if(f) break;
			else cout<<t*abs(r[k].x-r[k].y);
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<s[i].t[i];
		}
	}
	return 0;
} 
