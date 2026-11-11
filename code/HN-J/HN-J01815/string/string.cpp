#include <bits/stdc++.h>
using namespace std;
struct hw{
	long long d;
	string s;
};
hw a[1000000];

int cmp(hw a,hw b){
	return a.d>b.d;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,dd;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].d>>a[i].s;
		
		sum=sum + a[i].d;
		
	}
	for(int i=0;i<n;i++){
		if(a[i].s==a[i+1].s){
			a[i+1].d=(a[i+1].d)+(a[i].d);
			a[i].d=0;
		}
	}
	
	sort(a,a+n,cmp);
	if(sum%2==0){
		cout<<sum-a[0].d;
	}else{
		if(a[0].d>=(sum/2+1))
			cout<<sum-a[0].d;
		else{
			cout<<sum-a[0].d-1;
		}
	}
		
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
