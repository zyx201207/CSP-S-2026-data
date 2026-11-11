//GZ-J00310 遵义市第四中学 张君皓 
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,i,a[100001],d[10001],max,x,y,s,j,q;
	string b,c,g;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			while(a[i]>1){
				b+=a[i]%2;
				a[i]/2;
			}
			b+='1';
			while(a[i]>1){
				c+=a[i]%2;
				a[i]/2;
			}
			c+='1';
			x=b.size();
			y=c.size();
			if(x>y){
				max=x;
			}else{
				max=y;
			}
			for(int e=max;e>=1;e--){
				if(b[e]=='1'&&c[e]=='1'){
					g+='1';
				}else{
					g+='0';
				}
			}
			s=g.size();
			d[i]=g[0];
			for(int e=1;e<s;e++){
				for(int f=1;f<=e;f++){
					q=1;
					for(int p=1;p<=f;p++){
						q*=2;
					}
					d[i]+=e[f]*q;
				}
			}
		}
	}
	cout<<d[1];
	return 0;
}
