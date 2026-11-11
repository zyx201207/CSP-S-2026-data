#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long b[500005];
long long num=0;
int op=1, ans=-1;
long long cha;
int hd=1; 
int main(){
	//OK
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[1];//b[i]表示a[1]与a[i]的差 
	}
	for(int i=2;i<=n;i++){
		cha=a[i]-a[i-1];
		num+=op*cha;
//		cout<<num<<"   ";
		if(num>m){
			ans=max(ans, op);
			while(num>m){
				op-=1;
				num=num-(b[i]-b[hd]);
				hd+=1;
				if(hd>=i)break; 
			}
		}else if(num==m){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					op+=1;
				}else{
					break;
				}
			}
			ans=max(ans, op+1);
			op-=1;
			num=num-(b[i]-b[hd]);
			hd+=1;
		}
		op+=1;
//		cout<<num<<endl;
	}
	printf("%lld\n", ans);
    return 0;
}
