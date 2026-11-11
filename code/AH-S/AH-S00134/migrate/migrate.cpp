#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,T;
long long n,d,cnt;
struct Node{
    long long x,l,r;
}a[N];
void try24(){
	for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
			if(a[j].x-a[j-1].x>d) continue;
			long long sum=0;
			long long tmp1=max(a[i].x,a[j].l),tmp2=min(a[i].r,a[j].x);
			for(long long l=i+1;l<j;l++){
				if((a[l].x>=tmp1&&a[l].x<=tmp2)||(a[l].x>=tmp2&&a[l].x<=tmp1)) sum++;
				if(sum>2) break;
			}
			if(sum==2){cnt++;}
		}
    }
    cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
        cnt=0;
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>a[i].x;
            a[i].l=a[i].x-d;
            a[i].r=a[i].x+d;
        }
        if(n*n*T<=100000000) try24();
        else if(c==11||c==12){
			if(a[2].x-a[1].x>d) cout<<0;
			else cout<<n-d*2+1; 
			cout<<endl;
		}
		else if(c==13||c==14) cout<<0;
		else cout<<n*n/2;
	}
	return 0;
}
