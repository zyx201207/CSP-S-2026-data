#include<bits/stdc++.h>
using namespace std; 
const long long N=2e5+5;
long long n,m,x,y,z,op,sum,t,k,a[N],f[N],flag,js,ans,l,r,na[N],fi[N],fj[N];
char b[N],nb[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],sum+=a[i];
	for(int i=1;i<=n;i++){
		js+=a[i];
		l=js-a[i]+1;
		r=js;
		if((sum%2)==1){
			if((r==(sum/2+1))||(l==(sum/2+1))){
				na[++t]=a[i]-1;
				nb[t]=b[i];
			}
			else if((l<(sum/2+1))&&(r>(sum/2+1))){
				na[++t]=sum/2+1-l;
				nb[t]=b[i];
				na[++t]=r-(sum/2+1);
				nb[t]=b[i];
			}
			else{
				na[++t]=a[i];
				nb[t]=b[i];
			}
		}
		else{
			if((l<(sum/2+1))&&(r>(sum/2))){
				na[++t]=sum/2+1-l;
				nb[t]=b[i];
				na[++t]=r-(sum/2);
				nb[t]=b[i];
			}
			else{
				na[++t]=a[i];
				nb[t]=b[i];
			}
		}
	}
	if((sum%2)==1)
		sum--;
//	for(int i=1;i<=n;i++)
//		cout<<na[i]<<" "<<nb[i]<<"\n";
	for(int i=1,j=t;;){
		if(fi[j]||fj[i])
			break;
		fi[i]=1,fj[j]=1;
		if(na[i]==na[j]){
			if(nb[i]!=nb[j])
				ans+=na[i];
			i++,j--;
		}
		if(na[i]<na[j]){
			if(nb[i]!=nb[j])
				ans+=na[i];
			na[j]-=na[i],i++;
		}
		if(na[i]>na[j]){
			if(nb[i]!=nb[j])
				ans+=na[j];
			na[i]-=na[j],j--;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
