#include<bits/stdc++.h>
#define N int(2e6+1)
using namespace std;
int t, c, n, d, x[N], cnt, a[N];
long long ans;
/*struct {
	int l, r;
}fa[N];*/
bool flag[N];
int read() {
	int f=1, cnt=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f*=-1, ch=getchar();
	while(ch<='9'&&ch>='0') cnt=cnt*10+ch-'0', ch=getchar();
	return f*cnt;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	c=read(), t=read();
	while(t--) {
		memset(flag, 0, sizeof(flag));
		ans=0, cnt=0;
		n=read(), d=read();
		for(int i=1; i<=n; i++){
			x[i]=read();
			if(i>3){
				if(x[i]-x[i-3]>d&&x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d) a[i-3]=++cnt;
			}
		} 
		
		if(cnt==0){
			cout<<"0\n";
			continue ;
		} 
		for(int i=1; i<=n; i++) {
			if(flag[i]) continue;
			bool qf=0;
			int been=1, add=0, k=i;
			
			while(k<n) {
				if(!qf&&a[k]>0)  qf=1, k+=3, add=1;
				int j=k+1;
				if(k==n) break;
				if(x[k+1]-x[k-1]<=d) ans+=1LL*add*been, qf=0, k--, flag[k]=1, been++, add=0;
				while(j+1<=n&&x[j+1]-x[k]<=d) { 
					j++;
				}
				if(!qf){
					if(a[j]==0)k=j, been++;
					else been++, qf=1, k=j+3, add=1;
					flag[j]=1, flag[k]=1;
				}
				if(qf) {
					if(a[j]==0)k=j, add=1;
					else if(x[j+5]-x[j+3]<d) k=j+3, been+=2;
					else {
						add=1;
						
						break;
					}
				}
				//cout<<"a ";
				
			}
			ans+=1LL*add*been;
			//cout<<ans<<" "<<i<<"\n";
		}
		cout<<ans<<"\n";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
