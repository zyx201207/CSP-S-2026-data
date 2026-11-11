#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
char c[N],d[N];
ll a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,sum=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>d[i];
		sum+=b[i];
	} 
//	for(int i=1;i<=n;i++) cout<<b[i]<<' '<<d[i]<<'\n';
	ll remain=0,i;
	for(i=1;i<=n;i++){
		++cnt;
		if((remain+b[i])<=(sum>>1)) a[cnt]=b[i],c[cnt]=d[i];
		else{
			if(sum&1){
				if((sum>>1)-remain!=0) a[cnt]=(sum>>1)-remain,c[cnt]=d[i];
				++cnt;
				remain+=b[i];
				a[cnt]=(remain-(sum>>1)-1),c[cnt]=d[i];
			}else{
				if((sum>>1)-remain!=0) a[cnt]=(sum>>1)-remain,c[cnt]=d[i];
				++cnt;
				remain+=b[i];
				a[cnt]=(remain-(sum>>1)),c[cnt]=d[i];
			}
			i++;
			break;
		}
		remain+=b[i];
	}
	for(;i<=n;i++){
		++cnt;
		a[cnt]=b[i],c[cnt]=d[i];
		remain+=b[i];
	}
//	cout<<sum<<'\n';
//	for(int i=1;i<=cnt;i++) cout<<a[i]<<' '<<c[i]<<'\n'; 
//	cout<<cnt<<'\n';
	ll ans=0,j=cnt,L=0,R=0;
	i=1;
	while(i<=j){
		if(L==0) L+=a[i++]; 
		if(R==0) R+=a[j--];
		if(c[i-1]!=c[j+1]){
			if(L>R) L-=R,ans+=R;
			else if(L==R) ans+=L,L=0,R=0;
			else R-=L,ans+=L;
		}else{
			if(L>R) L-=R;
			else if(L==R) L=0,R=0;
			else R-=L;
		}
	}
	cout<<ans;
} 
