#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
struct node{
	char arr;
	int len;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,pos=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		char ch;cin>>ch;
		if(i==1){
			a[i].arr=ch;
			a[i].len=l;
			pos++;
			continue;
		}
		if(a[pos].arr==ch){
			a[pos].len+=l;
		}else{
			pos++;
			a[pos].arr=ch;
			a[pos].len=l;
		}
	}
	int i=1,j=pos;
	while(i<j){
		if(a[i].arr!=a[j].arr){
			if(a[i].len<a[j].len){
				ans+=a[i].len;
				a[j].len-=a[i].len;
				i++;
			}else{
				ans+=a[j].len;
				a[i].len-=a[j].len;
				j--;
			}
		}else{
			if(a[i].len<a[j].len){
				i++;a[j].len-=a[i].len;
			}else{
				j--;a[i].len-=a[j].len;
			}
		}
	}
	cout<<ans;
	return 0;
}
