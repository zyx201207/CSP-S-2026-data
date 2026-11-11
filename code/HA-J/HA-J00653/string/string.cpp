#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct node{
	long long num;
	char s;
}f[N],a[N],b[N];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].num>>f[i].s;
		sum+=f[i].num;
	}
	bool flag=1;
	if(sum%2==1){
		flag=0;
	}
	sum/=2;
	long long sum2=0;
	for(int i=1;i<=n;i++){
		if(sum2>=sum) break;
		if(f[i].num+sum2>=sum) {
			a[i].num=sum-sum2;
			a[i].s=f[i].s;
			sum2=sum;
			break;
		}
		else{
			a[i].num=f[i].num;
			sum2+=f[i].num;
			a[i].s=f[i].s;
		}
	}
	sum2=0;
	int j1=n;
	for(int i=1;i<=n;i++){
		if(sum2>=sum) break;
		if(f[j1].num+sum2>=sum) {
			b[i].num=sum-sum2;
			b[i].s=f[j1].s;
			sum2=sum;
			break;
		}
		else{
			b[i].num=f[j1].num;
			sum2+=f[j1].num;
			b[i].s=f[j1].s;
		}
		j1--;
	}
	for(int i=1,j=1;i<=n,j<=n;){
		if(a[i].num==b[j].num){
			if(a[i].s==b[j].s){
				i++,j++;
				continue;
			}else{
				ans+=a[i].num;
				i++,j++;
				continue;
			}
		}else{
			if(a[i].num>b[j].num){
				if(a[i].s==b[j].s){
					a[i].num-=b[j].num;
					j++;
					continue;
				}else{
					ans+=b[j].num;
					a[i].num-=b[j].num;
					j++;
					continue;
				}
			}
			if(a[i].num<b[j].num){
				if(a[i].s==b[j].s){
					b[j].num-=a[i].num;
					i++;
					continue;
				}else{
					ans+=a[i].num;
					b[j].num-=a[i].num;
					i++;
					continue;
				}
			}
		}
	}
	cout<<ans;
}