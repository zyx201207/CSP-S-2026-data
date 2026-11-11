#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,res,len,sum,pos=1,mid;
struct f{
	char k;
	int len; 
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].len>>a[i].k,sum+=a[i].len;
	if(sum%2)mid=(sum+1)/2;
	else mid=sum/2;
	for(int i=1;i<=n;i++){
		if(sum%2){
			if(pos+a[i].len-1==mid){
				a[i].len--;
				break;
			}
			else if(pos+a[i].len-1>mid){
				for(int j=n+1;j>=i+2;j--){
					a[j]=a[j-1];
				}
				a[i+1].len=pos+a[i].len-1-mid;
				a[i+1].k=a[i].k;
				a[i].len=mid-pos;
				n++;
				break;
			}
		}
		else{
			if(pos+a[i].len-1>mid){
				for(int j=n+1;j>=i+2;j--){
					a[j]=a[j-1];
				}
				a[i+1].len=pos+a[i].len-1-mid;
				a[i+1].k=a[i].k;
				a[i].len=mid-pos+1;
				n++;
				break;
			}
		}
		pos+=a[i].len;
	}
	for(int l=1,r=n,now=1;l<r;){
		if(a[l].len>a[r].len){
			now+=a[r].len;
			if(a[l].k!=a[r].k)res+=a[r].len;
			a[l].len-=a[r].len;
			r--;
		}
		else if(a[r].len>a[l].len){
			now+=a[l].len;
			if(a[r].k!=a[l].k)res+=a[l].len;
			a[r].len-=a[l].len;
			l++;
		}
		else{
			if(a[l].k!=a[r].k)res+=a[l].len;
			l++,r--;
			now+=a[l].len;
		}
	}
	cout<<res;
	return 0;
}
