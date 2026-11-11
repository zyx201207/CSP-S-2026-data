#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n,sum=1;
long long m;
int a[N+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cnt,mid;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	if((a[1]+a[n])*n/2==cnt){
		int p=n-1;
		while(m--){
			a[p]++;
			if(a[p]==a[n]){
				p--;
				sum++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			mid+=a[i];
		}
		mid/=2;
		sort(a,a+n+1);
		int minx=INT_MAX,num;//num:ÏÂ±ê cha:²î 
		for(int i=1;i<=n;i++){
			int cha=abs(a[i]-mid);
			if(cha<minx){
				minx=cha;
				num=i;
			}
		}
		int p=num-1;
		while(m--){
			if(a[p]==a[num]){
				p++;
				sum++;
			}
			a[p]++;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
