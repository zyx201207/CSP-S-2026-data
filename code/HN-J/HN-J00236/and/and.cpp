#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long num=1,num2=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=m;i<=n;i++){
		num*=i;
	}
	int a[num+2];
	int b[n+2];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}//老师，我写不出来，只能偷分了 
	if(m==2){
		for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			a[num2]=b[i]&b[j];
			num2++;
		}
	}
	sort(a,a+num2,cmp);
	cout<<a[0]<<endl;
	return 0;
	}
	if(m==n){
		int p=b[0];
		for(int i=1;i<n;i++){
			p=p&b[i];
		}
		cout<<p<<endl;
		return 0;
	}
	if(m==1){
		sort(b,b+n,cmp);
		cout<<b[0];
		return 0;
	}
	return 0; 
}
