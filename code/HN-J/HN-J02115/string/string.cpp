#include<bits/stdc++.h>
using namespace std;
struct q{
	long long s1;
	char s2;
} a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long zj=0;
	for(int z=1;z<=n;z++){
		cin>>a[z].s1>>a[z].s2;
		zj+=a[z].s1;
	}
	long long cs=0;
	zj=(zj+1)/2;
	for(long long z=1,cq=1,ch=1,qm=a[1].s1,qm1=a[1].s2,hm=a[n].s1,hm1=a[n].s2;z<=n;z++){
		if(qm>=hm){
			if((int)qm1!=(int)hm1){
				cs+=hm;
			}
			hm1=a[n-ch].s2;
			qm-=hm;
			hm=a[n-ch].s1;
			ch++;
		}
		else{
			if((int)hm1!=(int)qm1){
				cs+=qm;
			}
			qm1=a[cq+1].s2;
			hm-=qm;
			qm=a[cq+1].s1;
			cq++;
		}
	}
	cout<<cs;
	return 0;
}

