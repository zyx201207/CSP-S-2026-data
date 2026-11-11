#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,a[N];
long long cnt,ans;
bool b=0;
char c[N],s;
void str(int az,int ay,char z,char y){
	if(z!=y){
		if(az>ay){
			cnt=az-ay;
			s=z;
			ans+=ay;
			b=0;
		}
		else if(az<ay){
			cnt=ay-az;
			s=y;
			ans+=az;
			b=1;
		}
		else{
			cnt=0;
			ans+=az;
		}
	}
	else{
		if(az>ay){
			cnt=az-ay;
			s=z;
			b=0;
		}
		else if(az<ay){
			cnt=ay-az;
			s=y;
			b=1;
		}
		else{
			cnt=0;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cntn,sumn,mid,m,j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cntn+=a[i];
	}
	if(cntn%2==0){
		mid=cntn/2;
	}
	else{
		mid=cntn/2+1;
	}
	for(int i=1;i<=n;i++){
		sumn+=a[i];
		if(sumn>=mid){
			m=i;
			break;
		} 
	}
	for(int i=1;i<m;i++){	
		if(cnt!=0){
			if(b==0){
				str(cnt,a[j],s,c[j]);	
			}
			else{	
				str(a[i],cnt,c[i],s);	
			}	
		}
		else{
			str(a[i],a[j],c[i],c[j]);
			if(j>=m){
				j--;
			}
		}	
	}
	if(cnt!=0){
		str(cnt,a[j],s,c[j]);
	}
	cout<<ans;
	return 0;
}
