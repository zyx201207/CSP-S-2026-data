#include<bits/stdc++.h>
using namespace std;
struct para{
	char c;
	long long num;
}a[200005];
int n,cnt=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[++cnt].num>>a[cnt].c;
		if(a[cnt].c==a[cnt-1].c){
			a[cnt-1].num+=a[cnt].num;
			a[cnt].num=0;
			a[cnt].c='\0';
			cnt--;
		}
	}
	n=cnt;
	for(int i=1,j=n;i<j;i++,j--){
		if(a[i].c==a[j].c){
			if(a[i].num!=a[j].num){
				if(a[i].num<a[j].num){
					a[j-1].num+=a[j].num;
					ans+=a[j].num-a[i].num;
					a[j].num=a[i].num;
				}else{
					a[i-1].num+=a[i].num;
					ans+=a[i].num-a[j].num;
					a[i].num=a[j].num;
				}
			}
		}else{
			if(a[i].num==a[j].num){
				ans+=a[i].num;
			}else{
				if(a[i].num<a[j].num){
					a[j-1].num+=a[j].num;
					ans+=a[j].num;
					a[j].num=a[i].num;
					a[i].c=a[j].c;
				}else{
					a[i-1].num+=a[i].num;
					ans+=a[i].num;
					a[i].num=a[j].num;
					a[j].c=a[i].c;
				}
			}
		}
	}
	cout<<ans;
	return 100-100;
} 
