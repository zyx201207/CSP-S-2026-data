#include<bits/stdc++.h>
#define ll long long
#define HFL (l/2+1)
#define DBG 0
using namespace std;
ll n,l,a[200005];
ll lft[200005],rgt[200005];
ll al[200005],ar[200005],
	bl[200005],br[200005];
char st[200005],ac[200005],bc[200005];
ll GAN(ll l,ll i){
	return (ll)(l+1-i);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>st[i];
		lft[i]=l+1;l+=a[i];rgt[i]=l;
	}
	if(DBG) for(int i=1;i<=n;i++) cout<<lft[i]<<" "<<rgt[i]<<endl;
	if(DBG) cout<<"L="<<l<<endl;
	if(DBG) cout<<endl<<endl<<"---------------------------------"<<endl<<"al&ar :";
	int tmp;
	for(tmp=1;tmp<=n;tmp++){
		if(rgt[tmp]>=HFL){
			al[tmp]=lft[tmp],ar[tmp]=HFL,ac[tmp]=st[tmp];
			break;
		}
		al[tmp]=lft[tmp],ar[tmp]=rgt[tmp],ac[tmp]=st[tmp];
		if(DBG) cout<<"tmp:"<<tmp<<" ----- "<<al[tmp]<<" "<<ar[tmp]<<endl;
	}
	ll borderb;
	if(DBG) cout<<endl<<endl<<"---------------------------------"<<endl<<"bl&br :";
	for(tmp=n;tmp>=1;tmp--){
		if(rgt[tmp]<HFL){
			bl[tmp]=rgt[tmp],br[tmp]=HFL+1,bc[tmp]=st[tmp];
			borderb=tmp;
			break;
		}
		bl[tmp]=rgt[tmp],br[tmp]=lft[tmp],bc[tmp]=st[tmp];
		if(DBG) cout<<"tmp:"<<tmp<<" ----- "<<bl[tmp]<<" "<<br[tmp]<<endl;
	}
	if(DBG) cout<<endl<<endl<<"---------------------------------"<<endl<<"FUNC :\n";
	ll sum=0;
	for(int i=1;i<=borderb;i++){
		ll l1=al[i],r1=ar[i];
		if(DBG) cout<<"l1&r1 of i in "<<i<<" is "<<l1<<" and "<<r1<<"."<<endl;
		for(int j=n;j>=i;j--){
			ll l2=GAN(l,bl[j]),
				r2=GAN(l,br[j]);
			if(DBG) cout<<"l2&r2 of i in "<<i<<" and j in "<<j<<" is "<<l2<<" and "<<r2<<"."<<endl<<"WARING:BRJ="<<br[j]<<endl;
			if(l1<=l2&&l2<=r1&&ac[i]!=bc[j]){
				sum+=min(r1,r2)-l2+1;
				if(DBG) cout<<"INTO IF; sum="<<sum<<endl;
				if(r2>=r1){
					bl[j]=GAN(l,al[i+1]);
					if(DBG) cout<<"r2>=r1, bl_j have been changed into "<<bl[j]<<".\n";
				}
			}
			if(l2>r1){
				if(DBG) cout<<"l2>r1, break of while."<<endl;
				break;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
// WA
