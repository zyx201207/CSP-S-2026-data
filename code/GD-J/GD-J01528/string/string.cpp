#include<iostream>
using namespace std;
int n,a[200010];
char c[200010];
long long ans=0,count=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		count+=a[i];
	}
	int cnt1=0,cnt2=count-1,mid,letter1=0,num1=0,letter2=n-1,num2=n-1;
	if(count%2) mid=count/2+1;
	else mid=count/2;
	while(cnt1<=mid&&cnt2>=mid){
		if(a[num1]<=0){
			++letter1;
			++num1;
		}
		if(a[num2]<=0){
			--letter2;
			--num2;
		}
		++cnt1;
		--cnt2;
		if(cnt1==cnt2) --a[num1];
		else{
			--a[num1];
			--a[num2];
		}
		if(c[letter1]!=c[letter2]) ++ans;
	}
	cout<<ans;
	return 0;
}
