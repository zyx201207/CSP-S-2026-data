#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
long long cnt,lcnt,rcnt,ex,les,res;
char p[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>p[i];
		cnt+=a[i];
	}
	int l=1,r=n;
	while(l<r){
		if(p[l]!=p[r]){
			if(a[l]==a[r]){
				ex+=a[l];
				lcnt+=a[l];
				rcnt+=a[l];
				l++;
				r--;
			}else{
				if(a[l]>a[r]){
					ex+=a[r];
					lcnt+=a[r];
					rcnt+=a[r];
					a[l]-=a[r];
					r--;
				}else{
					ex+=a[l];
					lcnt+=a[l];
					rcnt+=a[l];
					a[r]-=a[l];
					l++;
				}
			}
		}else{
			if(a[l]==a[r]){
				lcnt+=a[l];
				rcnt+=a[r];
				l++;
				r--;
			}else{
				if(a[l]>a[r]){
					lcnt+=a[r];
					rcnt+=a[r];
					a[l]-=a[r];
					r--;
				}else{
					lcnt+=a[l];
					rcnt+=a[l];
					a[r]-=a[l];
					l++;
				}
			}
		}
	}
	cout<<ex;
	return 0;
}
