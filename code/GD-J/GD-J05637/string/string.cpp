#include <iostream>
#include <cstring>
using namespace std;
long long n,sum,mid,b,qn,hn,index,qi,hi,qxn,hxn,ans,mi;
long long a[200005];
char c[200005],qxc,hxc;
long long qs[200005],hs[200005];
char qc[200005],hc[200005];
long long min(long long a,long long b){
	return (a>b?b:a);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
	}
	mid=sum/2;
	for(int i=1;i<=n;i++){
		b+=a[i];
		++index;
		if(b<=mid){
			if(c[i]==qc[qn]){
				qs[qn]+=a[i];
			}
			else{
				qs[++qn]=a[i];
				qc[qn]=c[i];
			}
		}
		else{
			if(c[i]==qc[qn]){
				qs[qn]+=a[i]-(b-mid);
				a[i]=b-mid;
			}
			else{
				qs[++qn]=a[i]-(b-mid);
				qc[qn]=c[i];
				a[i]=b-mid;
			}
			break;
		}
		if(b==mid){
			++index;
			break;
		}
	}
	if(sum%2==1){
		a[index]--;
	}
	for(int i=n;i>=index;i--){
		if(c[i]==hc[hn]){
			hs[hn]+=a[i];
		}
		else{
			hs[++hn]=a[i];
			hc[hn]=c[i];
		}
	}
	while(qi<=qn&&hi<=hn){
		if(qxn==0){
			qxn=qs[++qi];
			qxc=qc[qi];
		}
		if(hxn==0){
			hxn=hs[++hi];
			hxc=hc[hi];
		}
		if(qxc==hxc){
			mi=min(qxn,hxn);
			qxn-=mi;
			hxn-=mi;
		}
		else{
			if(qxn<hxn){
				qxc=hxc;
				ans+=qxn;
			}
			else{
				hxc=qxc;
				ans+=hxn;
			}
		}
	}
	cout<<ans;
	return 0;
}
