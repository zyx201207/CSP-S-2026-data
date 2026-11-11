#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],l[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	bool bl=1;
	
	for(int i=1;n>=i;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long la=a[2],c=a[1]-a[2];
	for(int i=3;n>=i;i++){
		if(la-a[i]!=c)bl=0;
		la=a[i];
	}
	c=abs(c);
	if(bl){
		for(long long i=0;1500000>=i*c;i++){
			if(c*i*(i+1)>m*2){
				if(i>n)i=n;
				cout<<i;//+1;
				return 0;
			}
		}
	}
	else{
		long long ma=-1000000000;
		for(int i=1;n>=i;i++){
			for(int j=1;i>=j;j++){
				l[j]=a[i]-a[j];
			}
			sort(l+1,l+i+1);
			long long mm=m,cnt=0;
			while(mm){
				mm-=l[cnt+2];
				if(cnt>=i || 0>mm)break;
				cnt++;
			}
			if(cnt==n)cnt--;
			ma=max(ma,cnt+1);
		}
		cout<<ma;
	}
	return 0;
} 
