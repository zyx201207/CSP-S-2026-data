#include<iostream>
using namespace std;
int n,len,sum,cnt1,cnt2;
long long ans;
struct chars{
	int num;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].ch;
	cnt1=1,cnt2=n;
	while(cnt1<cnt2){
		if(a[cnt1].num<a[cnt2].num){
			if(a[cnt1].ch!=a[cnt2].ch) ans+=a[cnt1].num; 
			a[cnt2].num-=a[cnt1].num; cnt1++;
		}
		else if(a[cnt1].num>a[cnt2].num){
			if(a[cnt1].ch!=a[cnt2].ch) ans+=a[cnt2].num; 
			a[cnt1].num-=a[cnt2].num; cnt2--;
		}
		else{
			if(a[cnt1].ch!=a[cnt2].ch) ans+=a[cnt1].num; 
			cnt1++,cnt2--;
		}
	}
	cout<<ans;
	return 0;
}
