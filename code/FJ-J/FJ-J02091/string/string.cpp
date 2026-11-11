#include<bits/stdc++.h>
using namespace std;
struct lj{
	char s;
	long long b;
	long long e;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=1;
	for(int i=1;i<=n;i++){
		int l;char st;
		cin>>l>>st;
		a[i].s=st;
		a[i].b=num;
		a[i].e=num+l-1;
		num+=l;
	}
	long long mid=-1;
	if(num%2==0)mid=num/2;
	long long sum=0,lef=0,rig=0;
	int flag[200005]={0};
	for(int i=1,j=n;;){
//		cout<<i<<" "<<j<<" "<<sum<<"\n";
		if(flag[i]==2||flag[j]==1)break;
		flag[i]=1;
		flag[j]=2;
		lef=a[i].e;
		rig=a[j].b;
		if(mid!=-1){
			if(lef>=mid)lef=mid-1;
			if(rig<=mid)rig=mid+1;
		}else{
			if(lef>num/2)lef=num/2;
			if(rig<=num/2)rig=num/2+1;
		}
//		cout<<lef<<" "<<rig<<"\n";
		if(a[i].s!=a[j].s){
			if(num-lef<rig){
				sum+=abs(rig-min(num-a[i].b,a[j].e))+1;
				j--;
			}else if(num-lef==rig){
				sum+=abs(rig-min(num-a[i].b,a[j].e))+1;
				i++;
				j--;
			}else{
				sum+=abs(lef-max(num-a[j].e,a[i].b))+1;
				i++;
			}
		}else{
			if(num-lef<rig){
				j--;
			}else if(num-lef==rig){
				i++;
				j--;
			}else{
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
