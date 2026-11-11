#include <bits/stdc++.h>
using namespace std;
long long n,nz;
string s;
long long al[200100],ar[200100];
long long a[200100];
char b[200100],bl[200100],br[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		nz+=a[i];
	}
	long long ll=nz/2,rr=nz/2;
	for(int i=0;i<n;i++){
		if(a[i]<=ll){
			al[i]=a[i];
			bl[i]=b[i];
			ll-=a[i];
		}else{
			al[i]=ll;
			bl[i]=b[i];
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[n-i-1]<=rr){
			ar[i]=a[n-i-1];
			br[i]=b[n-i-1];
			rr-=a[n-i-1];
		}else{
			ar[i]=rr;
			br[i]=b[n-i-1];
			break;
		}
	}
	long long cc=nz/2,dd;
	int l=0,r=0;
	while(cc){
		if(al[l]>ar[r]){
			al[l]-=ar[r];
			cc-=ar[r];
			if(bl[l]!=br[r]){
				dd+=ar[r];
			}
			r++;
		}else if(al[l]<ar[r]){
			ar[r]-=al[l];
			cc-=al[l];
			if(bl[l]!=br[r]){
				dd+=al[l];
			}
			l++;
		}else{
			if(bl[l]!=br[r]){
				dd+=al[l];
			}
			l++;
			r++;
		}
	}
	cout<<dd;
	return 0;
}
