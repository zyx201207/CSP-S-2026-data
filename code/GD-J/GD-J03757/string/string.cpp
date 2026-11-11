#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len;
struct node{
	int l,id;
	char ch;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].ch;
		len+=a[i].l;
		a[i].id=len;
	}
	int mid=len/2,ans=0;
	if(len%2==1)mid++;
	for(int i=1;i<=n;i++){
		if(a[i].id<=mid)continue;
		else{
			if(a[i-1].id<mid){
				cout<<"flag"<<endl;
				int out=a[i].id-mid,pass=a[i].l-out;
				if(out<pass)continue;
				else{
					for(int j=1;j<=i-1&&out>0;j++){
						if(a[i].ch==a[j].ch){
							out-=a[i].l;
						}
					}
					if(out<=0)continue;
					ans+=out;
					continue;
				}
			}
			else{
				int tar=len-a[i].id+1,clen=a[i].l;
				for(int j=1;a[j].id<=tar&&clen>0;j++){
					if(a[i].ch==a[j].ch){
						clen-=a[i].l;
					}
				}
				if(clen<=0)continue;
				else ans+=clen;
			}
		}
	}
	cout<<ans;
	return 0;
} 
