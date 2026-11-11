#include <bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	double se=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		se+=a[i];
	}
	sort(a,a+n);
	int befor=0,now=0;
	do{
		se/=n;
		long long sepos,sema;
		for(long long i=0;i<n-1;i++){
			if(se>a[i] && se<a[i+1]){
				long long st=abs(se-a[i]),cd=abs(se-a[i+1]);
				if(st<cd){
					sepos=i;
				}
				else{
					sepos=i+1;
				}
				break;
			}
		}
		bool flag=false;
		long long ans=0,oldpos=sepos,nextpos;
		for(long long i=sepos;a[i]==a[sepos];i++){
			ans++;
		}
		while (sepos>=1){
			if(a[oldpos]-a[sepos-1]<=m){
				m-=a[oldpos]-a[--sepos];
				a[sepos]=a[oldpos];
				ans++;
			}
			else{
				break;
			}
		}
		befor=now;
		now=ans;
	}while(befor!=now);
	cout<<now;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
