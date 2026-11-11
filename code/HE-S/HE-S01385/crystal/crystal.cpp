#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500003],max1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long j=1,h=1,num=1,f=m;
		while(f){
			if(abs(a[i]-a[i+h])>=abs(a[i]-a[i-j])&&f-abs(a[i]-a[i-j])>=0&&i-j>0){
				f-=abs(a[i]-a[i-j]);
				j++;
				num++;
			}else if(f-abs(a[i]-a[i+h])>=0&&i+h<=n){
				f-=abs(a[i]-a[i+h]);
				h++;
				num++;
			}else{
				break;
			}
		}
		max1=max(num,max1);
		f=m;
	} 
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
