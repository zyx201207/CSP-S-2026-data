#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,cnt=0,l;
struct node{
	int x;
	string s;
}a[N],b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;	
		l+=a[i].x;
	}
	int l1=0,j=1,k;
	if(l%2==0){
		for(int i=1;i<=n;i++){
			if(a[i].x+l1<=l/2){
				b[j].x=a[i].x;
				b[j].s=a[i].s;
				l1+=a[i].x;
			}else{
				b[j].x=l/2-l1;
				a[i].x-=b[j].x;
				b[j].s=a[i].s;
				l1=l/2;
			}
			if(l1==l/2){
				k=i;
				break;
			}
			j++;
		}
		for(int i=k+1;i<=n;i++){
			j++;
			b[j].x=a[i].x;
			b[j].s=a[i].s;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i].x+l1<=l/2){
				b[j].x=a[i].x;
				b[j].s=a[i].s;
				l1+=a[i].x;
			}else{
				b[j].x=l/2+1-l1;
				a[i].x-=b[j].x;
				b[j].s=a[i].s;
				l1=l/2;
			}
			if(l1==l/2){
				k=i;
				break;
			}
			j++;
		}
		for(int i=k+1;i<=n;i++){
			j++;
			b[j].x=a[i].x;
			b[j].s=a[i].s;
		}
	}
	for(int i=1;i<=j/2;i++){
		if(b[i].s!=b[j/2+i].s){
			cnt+=b[j/2+i].x;
		}
	}
	cout<<cnt;
	return 0;
}

