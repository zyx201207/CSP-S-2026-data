#include<bits/stdc++.h>
using namespace std;
struct ss{
	long long l,r;
}bj[205];
long long n,m,a[500005],s[205],bc[205],pd=1,k,maxx,xc,pd2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>100 || a[i]<-100)
			pd=0;
		else
			s[a[i]+100]++;
		if(i>2 && (a[i]-a[i-1])!=xc)
			pd2=0;
		xc=a[i]-a[i-1];
	}
	if(pd2==1){
		long long w=0,xz=0,cs=0,lj=0,lj2=0,gs=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1])
				cs++;
			if(cs==1)
				gs++,lj++;
			else if(cs==2)
				lj2++;
			else{
				gs=lj;
				//cout<<lj<<" "<<lj2<<endl;
				if((w+xc*lj)<=m)
					w+=xc*lj;
				else if(((m-w)/xc+lj2)>gs){
					gs=((m-w)/xc+lj2);
					break;
				}
				else
					break;
				lj+=lj2,gs=lj,lj2=0,cs-=2,i--;
			}
		}
		printf("%lld",gs);
		return 0;
	}
	if(pd==1){ 
		for(int i=0;i<=200;i++){
			if(s[i]>0){
				long long wz=i+1;
				for(int j=i+1;j<=200;j++)
					if(s[j]>0){
						wz=j;
						break;
					}
				if(s[wz]>0)
					bj[++k].l=i,bj[k].r=wz;
				i=wz-1;
			}
		}
		for(int i=1;i<=k;i++){
			long long w=0,gs=s[bj[i].l];
			for(int j=0;j<=200;j++)
				bc[j]=s[j];
			for(int j=i;j<=k;j++){
				long long cj=bj[j].r-bj[j].l;
				if((w+cj*s[bj[j].l])<=m)
					w+=cj*s[bj[j].l],gs+=bc[bj[j].r],s[bj[j+1].l]+=s[bj[j].l];
				else if(((m-w)/cj+bc[bj[j].r])>gs){
					gs=((m-w)/cj+bc[bj[j].r]);
					break;
				}
				else
					break;
			}
			for(int j=0;j<=200;j++)
				s[j]=bc[j];
			maxx=max(maxx,gs);
		}
		printf("%lld",maxx);
		return 0;
	}
	printf("%lld",n);
	return 0;
} 
