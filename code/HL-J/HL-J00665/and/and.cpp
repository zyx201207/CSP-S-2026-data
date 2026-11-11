#include<iostream>
#include<cmath>
using namespace std;
long long n,m,maxn=0;
struct num{
	long long as;
	long long s;
};
num a[200005];
long long and_(long long x,long long y){
	long long ans;
	while(x>0||y>0){
		if(x%10==y%10){
			ans+=1;
		}
		else{
			ans+=0;
		}
		ans*=10;
	}
	return ans;
}
long long two_(long long n){
	long long sum=0;
	char ch[100000];
	int cnt=0;
	while(n>0){
		ch[cnt]=char(n%2+48);
		n/=2;
		cnt++;
	}
	cnt--;
	while(cnt>=0){
		sum+=int(ch[cnt]-48);
		cnt--;
		sum*=10;
	}
	sum/=10;
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].as;
		a[i].s=two_(a[i].as);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			else if(a[i].as==a[j].as) {
				if(a[i].as>maxn)
					maxn=a[i].as;
			}
		}
	}
	cout<<maxn;
	return 0;
}
