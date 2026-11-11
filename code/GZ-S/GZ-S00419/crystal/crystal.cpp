//GZ-S00419 黔南布依族苗族自治州都匀第一中学 孙皓辰

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long a[500010];
long long c[500010];
queue <long long> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	bool A=false,B=false;
	cin >>n >>m;
	if(n>5000) A=true,B=true;
	for(int i=1;i<=n;i++){
            cin >> a[i];
            if(a[i]!=i) A=false;
	}
	sort(a+1,a+n+1);
	c[1]=0;
	q.push(0);
	long long d = a[1];
	long long ans=0;
	long long p;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(i>2){
            if(c[i]!=p)
               B=false;
		}
        else p=c[i];
		if(m >= q.size() * c[i]){
			m -= q.size() * c[i];
			q.push(c[i]);
		}
		else{
			long long maxn=q.size();
			ans=max(ans,maxn);
			while(m < q.size() * c[i])
			    q.pop();
			m -= q.size() * c[i];
			q.push(c[i]);
		}
	}
	if(A){
        for(int i=1;i<=n;i++){
            if(i*(1+i)/2>m){
                ans=i-1;
                 break;
            }
        }
	}
	if(B){
        for(int i=1;i<=n;i++){
            long long mi=0;
            for(int j=1;j<=i;j++) mi*=p;
            if(a[1]*(1-mi)/(1-p)>m){
                    ans=i-1;break;
            }
        }
	}
	cout<<ans;
	return 0;

}
